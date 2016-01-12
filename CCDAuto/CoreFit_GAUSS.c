/************************************************************************
*  Routine:	CoreFit_GAUSS				                *
*  Purpose:	This routine will fit a signal distribution to a Four	*
*		parameter axisymmeteric Gaussian Model.			*
*  Date:	23 Aug 93						*
*  By:		A.L. Shoup (adapted from S. Biller's ReadPond		*
*************************************************************************/

/* 2000-SEP-05  added computation of coreDist[] 
    LF&RF       returns 0 on success
*/


#include <stdio.h>
#include <math.h>
#include "Reconstruction.h"

int mrqmin(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double covar[4][4], double alpha[4][4],
	    double *chisq, double *alambda);

#define PI2  6.28318530718

float G;
float chisq_ext;

int CoreFit_GAUSS(PMT_INFO *pmtInfo, CAL_DATA *calData, GRID_COORD * coords,
		  CORE_RECON *coreInfo, CORE_CONTROL *coreCon)
{

   /* Declare locals */

  static int i, j, igrid, nhit, Success, useTop, useBottom, useOutriggers;
  static double covar[4][4], alpha[4][4], parms[4];
  static double chisq, ochisq, alambda;
  float pesmax, xAS, yAS, xOUT, yOUT, xBoth, yBoth;
  float pe[1400], sig[1400], delx, dely, pes;
  float sigmaR, x[1400], y[1400];
  float sumpeAS, sumxAS, sumyAS, sumpeOUT[5], sumxOUT[5], sumyOUT[5];
  float ratioOutToTop, maxsumpe, xy;
  int maxquad, quad, wasItHit[MAX_OUTRIGGER_PMT];

  for (i=0; i<4; i++)
    for (j=0; j<4; j++) {
      alpha[i][j] = 0.0;
      covar[i][j] = 0.0;
    }

  memset(wasItHit,FALSE,sizeof(wasItHit));
  useTop = (((unsigned int)coreCon->layer) & 0x1);
  useBottom = (((unsigned int)coreCon->layer) & 0x2);
  useOutriggers = (((unsigned int)coreCon->layer) & 0x4);
  
  /* Compute fitting matrix and vector */

     /* AS pmts */

  sumpeAS = 0.0;
  sumxAS = 0.0;
  sumyAS = 0.0;
  for (quad=0; quad<5; quad++) {
    sumpeOUT[quad] = 0.0;
    sumxOUT[quad] = 0.0;
    sumyOUT[quad] = 0.0;
  }
  nhit = 0;
  pesmax = 0.0;
  for (i=1; i<calData->nPMTs; i++) {
    igrid = calData->gridNo[i];
    wasItHit[igrid] = TRUE;
    if (pmtInfo->dontFit[igrid]) continue;
    if (ASTUBE(igrid)) {
      if (!useTop) continue;
    } else if (MUTUBE(igrid)) {
      if (!useBottom) continue;
    } else if (ORTUBE(igrid)) {
      if (!useOutriggers) continue;
    }
    pes = calData->pes[igrid];
    if (pes > 10000.0) continue;
    if (pes < 1.0) {
      pe[nhit] = 0.0;
      sig[nhit] = 1.0;
    } else {
      pe[nhit]= pes;
      sig[nhit] = 1.0/pes;   /* Really 1.0 / square of sigma */
      if (pes > pesmax)
	pesmax = pes;
    }
    x[nhit] = coords->x[igrid];
    y[nhit] = coords->y[igrid];
    if (ASTUBE(igrid) || MUTUBE(igrid)) {
      sumpeAS += pes;
      sumxAS += pes*coords->x[igrid];
      sumyAS += pes*coords->y[igrid];
    } else if (ORTUBE(igrid)) {
      xy = x[nhit] * y[nhit];
      if (xy >= 0.0) {
	if (x[nhit] >= 0.0) {
	  quad = 1;
	} else {
	  quad = 3;
	}
      } else {
	if (x[nhit] > 0.0) {
	  quad = 4;
	} else {
	  quad = 2;
	}
      }
      sumxOUT[quad] += pes*x[nhit];
      sumyOUT[quad] += pes*y[nhit];
      sumpeOUT[quad] += pes;
      sumxOUT[0] += pes*x[nhit];
      sumyOUT[0] += pes*y[nhit];
      sumpeOUT[0] += pes;
    }
    nhit++;
  }

  for (i=MIN_AS_PMT; i<=MAX_OUTRIGGER_PMT; i++)
    if (! wasItHit[i]) {
      x[nhit] = coords->x[i];
      y[nhit] = coords->y[i];
      pe[nhit] = 0.0;
      sig[nhit] = 1.0;
      nhit++;
    } 
   
   ratioOutToTop = ((float) calData->nOUT) / ((float) calData->nAS);

   xAS = sumxAS/sumpeAS;
   yAS = sumyAS/sumpeAS;

   if (sumpeOUT[0] > 0.0) {
     xOUT = sumxOUT[0]/sumpeOUT[0];
     yOUT = sumyOUT[0]/sumpeOUT[0];
   } else {
     xOUT = 0.0;
     yOUT = 0.0;
   }

   xBoth = (sumxAS+sumxOUT[0])/(sumpeAS+sumpeOUT[0]);
   yBoth = (sumyAS+sumyOUT[0])/(sumpeAS+sumpeOUT[0]);

   parms[0] = (sumxAS+sumxOUT[0])/(sumpeAS+sumpeOUT[0]);
   parms[1] = (sumyAS+sumyOUT[0])/(sumpeAS+sumpeOUT[0]);
   parms[2] = coreCon->E;
   parms[3] = (sumpeAS+sumpeOUT[0])*coreCon->F;
   G = coreCon->G;
   if ((calData->nOUT<5) || (! useOutriggers)) {
     parms[0] = xAS;
     parms[1] = yAS;
     parms[2] = 800.0;
     parms[3] = sumpeAS*1700.0;
     G = 820.0;
   } else if (((calData->nOUT > 20) || (ratioOutToTop > 0.10)) &&
	      ((fabs(xOUT) > 3000.0) || (fabs(yOUT) > 4000.0))) {
     maxsumpe = -999.0;
     maxquad = -1;
     for (quad=1; quad<5; quad++) {
       if (sumpeOUT[quad] > maxsumpe) {
	 maxsumpe = sumpeOUT[quad];
	 maxquad = quad;
       }
     }
     xOUT = sumxOUT[maxquad]/sumpeOUT[maxquad];
     yOUT = sumyOUT[maxquad]/sumpeOUT[maxquad];
     parms[0] = xOUT;
     parms[1] = yOUT;
   }
   alambda = -1.0;
   Success = mrqmin(x,y,pe,sig,nhit,parms,covar,alpha,&chisq,&alambda);
   if (! Success) {
      coreInfo->xCoreF = parms[0];
      coreInfo->yCoreF = parms[1];
      coreInfo->errCore = -1.0;
      return 1;
   }

   do {
     ochisq = chisq; 
     Success = mrqmin(x,y,pe,sig,nhit,parms,covar,alpha,&chisq,&alambda);
     if (! Success) {
       coreInfo->xCoreF = parms[0];
       coreInfo->yCoreF = parms[1];
       coreInfo->errCore = -1.0;
       //       printf("*** INFO - Core Fit failed: %f %f %f %f %f\n",
       //	      parms[0],parms[1],parms[2],parms[3], chisq);
       return 1;
     }
   } while (((chisq>=ochisq)||(fabs(ochisq-chisq)>1.0)) &&
	    (fabs(log10(alambda)) < 30.0));

  alambda = 0.0;
  Success = mrqmin(x,y,pe,sig,nhit,parms,covar,alpha,&chisq,&alambda);
  if ((! Success) || (fabs(parms[0])>20000.0) || (fabs(parms[1])>20000.0)) {
    coreInfo->xCoreF = parms[0];
    coreInfo->yCoreF = parms[1];
    coreInfo->errCore = -1.0;
    //    printf("*** INFO - Core Fit failed for far off: %f %f %f %f %f\n", 
    //	   parms[0],parms[1],parms[2],parms[3], chisq);
    return 1;
  }

  sigmaR = 0.0;
	 
  coreInfo->xCoreF = parms[0];
  coreInfo->yCoreF = parms[1];
  coreInfo->errCore = sigmaR;
  chisq_ext = chisq/(nhit-4);

  for (i=1; i<calData->nPMTs; i++) {
     igrid = calData->gridNo[i];
     delx=parms[0]-coords->x[igrid];
     dely=parms[1]-coords->y[igrid];
     coreInfo->coreDist[igrid]=sqrt(delx*delx+dely*dely);
  }

  return 0;
}

void funcs(float x, float y, double a[4], double *zmod, double dzda[4])
{
  double argx, argy, expx, expy, argx2, argy2;

  argx = (x-a[0])/a[2];
  argx2 = argx*argx;
  argy = (y-a[1])/a[2];
  argy2 = argy*argy;
  if (fabs(argx) > 5.0)
    expx = 0.0;
  else
    expx = exp(-0.5*argx2);
  if (fabs(argy) > 5.0)
    expy = 0.0;
  else
    expy = exp(-0.5*argy2);
  *zmod = a[3]/(PI2*a[2]*a[2])*expx*expy;
  dzda[0] = argx/a[2] * *zmod;
  dzda[1] = argy/a[2] * *zmod;
  dzda[2] = *zmod/a[2]*(argx2 + argy2 - 2.0);
  dzda[3] = *zmod/a[3];
}



#include <stdio.h>
#include <math.h>

#define PI2  6.28318530718


int mrqmin(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double covar[4][4], double alpha[4][4],
	    double *chisq, double *alambda)

/* Levenberg-Marquardt Method:  attempting to reduce the value of Chi-sq of a
fit between a set of data points x[1..ndata], y[1...ndata], and z[1..ndata]
with individual standard deviations sig[1..ndata], and a nonlinear function
dependent on ma coefficients a[1..ma].  The input array ia[1..ma] indicates
by non-zero entries those components of a that should be fitted for, and by
zero entries those components which should be held fixed at their input values.
The routine returns current best-fit values for the parameters a[1..ma], and
chisq.  The arrays covar[1..ma][1..ma], alpha[1..ma][1..ma] are used as
working space during most iterations.  Supply a routine
funcs(x,y,a,zfit,dzda,ma) that evaluates the fitting function, yfit, its
derivatives dyda[1..ma] with respect to the fitting parameters a at (x,y). On
the first call provide an initial guess for the parameters a, and set alamda
< 0 for initialization (which then sets alambda = 0.001).  If a step succeeds
chisq becomes smaller and alambda decreases by a factor of 10.  If a step
fails alambda grows by a factor of 10.  You must call this routine repeatedly
until convergence is achieved.  Then make one final call with alambda=0, so
that covar[1..ma][1..ma] returns the covariance matrix, and alpha the
curvature matrix.  (Parameters held fixed will return zero covariances)
NOTE: modified for only 4 parameters */

{
  void covsrt(float **covar, int ma, int ia[], int mfit); 
  int gaussj(double a[4][4], double b[4][4]);
  void mrqcof(float x[], float y[], float z[], float sig[], int ndata,
	      double a[4], double alpha[4][4], double beta[4],
	      double *chisq);

  int j,k;
  static double ochisq, atry[4], beta[4], da[4], oneda[4][4];
  float temp;

  if (*alambda < 0.0) {            /* Initialization */
    *alambda = 1.0;
    mrqcof(x,y,z,sig,ndata,a,alpha,beta,chisq);
    ochisq = *chisq;
    atry[0] = a[0];
    atry[1] = a[1];
    atry[2] = a[2];
    atry[3] = a[3];
    for (j=0; j<4; j++)
      for (k=0; k<4; k++) oneda[j][k] = 0.0;
  }
  temp = 1.0 + *alambda;
  for (j=0; j<4; j++) {
    for (k=0; k<4; k++) covar[j][k] = alpha[j][k];
    covar[j][j] *= temp;
    oneda[j][0] = beta[j];
  }
  if (! gaussj(covar,oneda)) {  /* terminate fit */
    return FALSE;
  }
  da[0] = oneda[0][0];
  da[1] = oneda[1][0];
  da[2] = oneda[2][0];
  da[3] = oneda[3][0];
  if (*alambda == 0.0) {
    /* covsrt(covar); */
    return TRUE;
  }
  atry[0] = a[0] + da[0];
  atry[1] = a[1] + da[1];
  atry[2] = fabs(a[2]+da[2]);
  if (atry[2] > G) atry[2] = G;
  atry[3] = a[3] + da[3];
  mrqcof(x,y,z,sig,ndata,atry,covar,da,chisq);
  if (*chisq < ochisq) {
    *alambda *= 0.1;
    ochisq = *chisq;
    for (j=0; j<4; j++) {
      for (k=0; k<4; k++) alpha[j][k] = covar[j][k];
      beta[j] = da[j];
    }
    a[0] = atry[0];
    a[1] = atry[1];
    a[2] = atry[2];
    a[3] = atry[3];
  } else {
    *alambda *= 10.0;
    *chisq = ochisq;
  }
  return TRUE;
}

void mrqcof(float x[], float y[], float z[], float sig[], int ndata,
	    double a[4], double alpha[4][4], double beta[4], double *chisq)
{
  int i,j,k;
  double zmod,wt,sig2i,dz,dzda[4];

  for (j=0; j<4; j++) {
    for (k=0; k<=j; k++) alpha[j][k] = 0.0;
    beta[j] = 0.0;
  }
  *chisq = 0.0;
  for (i=0; i<ndata; i++) {
    funcs(x[i],y[i],a,&zmod,dzda);
    /*    if ((zmod < 0.5) && (z[i]< 0.5)) continue;*/
    sig2i = sig[i];
    dz = z[i] - zmod;
    for (j=0; j<4; j++) {
      wt = dzda[j]*sig2i;
      for (k=0; k<=j; k++) alpha[j][k] += wt*dzda[k];
      beta[j] += dz*wt;
    }
    *chisq += dz*dz*sig2i;
  }
  for (j=1; j<4; j++)
    for (k=0; k<j; k++) alpha[k][j] = alpha[j][k];
}



#include <stdio.h>
#include <math.h>

#define SWAP(a,b) {temp=(a);(a)=(b);(b)=temp;}

int gaussj(double a[4][4], double b[4][4])
{
  static int indxc[4]={0}, indxr[4]={0}, ipiv[4]={0};
  static int i, icol, irow, j, k, l, ll;
  static double big, dum, pivinv, temp;

  ipiv[0] = 0;
  ipiv[1] = 0;
  ipiv[2] = 0;
  ipiv[3] = 0;

  for (i=0; i<4; i++) {
    big = 0.0;
    for (j=0; j<4; j++)
      if (ipiv[j] != 1)
	for (k=0; k<4; k++) {
	  if (ipiv[k] == 0) {
	    if (fabs(a[j][k]) > big) {
	      big = fabs(a[j][k]);
	      irow = j;
	      icol = k;
	    }
	  } else if (ipiv[k] > 1) {
	    /*	    printf("\ngaussj: Singular Matrix-1"); */
	    return FALSE;
	  }
	}
    ++(ipiv[icol]);
    if (irow != icol) {
      for (l=0; l<4; l++) SWAP(a[irow][l],a[icol][l]);
      for (l=0; l<4; l++) SWAP(b[irow][l],b[icol][l]);
    }
    indxr[i] = irow;
    indxc[i] = icol;
    if (a[icol][icol] == 0.0) {
      /*      printf("\ngaussj: Singular Matrix-2"); */
      return FALSE;
    }
    pivinv = 1.0/a[icol][icol];
    a[icol][icol] = 1.0;
    for (l=0; l<4; l++) a[icol][l] *= pivinv;
    for (l=0; l<4; l++) b[icol][l] *= pivinv;
    for (ll=0; ll<4; ll++)
      if (ll != icol) {
	dum = a[ll][icol];
	a[ll][icol] = 0.0;
	for (l=0; l<4; l++) a[ll][l] -= a[icol][l]*dum;
	for (l=0; l<4; l++) b[ll][l] -= b[icol][l]*dum;
      }
  }
  for (l=3; l>=0; l--) {
    if (indxr[l] != indxc[l])
      for (k=0; k<4; k++)
	SWAP(a[k][indxr[l]],a[k][indxc[l]]);
  }
  return TRUE;
}
