#include "stdafx.h"
#include "doRoutines.h"

namespace CCDAuto {


void sla_FITXY(int ITYPE, int NP, double XYE[2][100], double XYM[2][100],
			   double COEFFS[6], int *J) {
/*
*     - - - - - -
*      F I T X Y
*     - - - - - -
*
*  Fit a linear model to relate two sets of [X,Y] coordinates.
*
*  Given:
*     ITYPE    i        type of model: 4 or 6 (note 1)
*     NP       i        number of samples (note 2)
*     XYE     d(2,np)   expected [X,Y] for each sample
*     XYM     d(2,np)   measured [X,Y] for each sample
*
*  Returned:
*     COEFFS  d(6)      coefficients of model (note 3)
*     J        i        status:  0 = OK
*                               -1 = illegal ITYPE
*                               -2 = insufficient data
*                               -3 = singular solution
*
*  Notes:
*
*  1)  ITYPE, which must be either 4 or 6, selects the type of model
*      fitted.  Both allowed ITYPE values produce a model COEFFS which
*      consists of six coefficients, namely the zero points and, for
*      each of XE and YE, the coefficient of XM and YM.  For ITYPE=6,
*      all six coefficients are independent, modelling squash and shear
*      as well as origin, scale, and orientation.  However, ITYPE=4
*      selects the "solid body rotation" option;  the model COEFFS
*      still consists of the same six coefficients, but now two of
*      them are used twice (appropriately signed).  Origin, scale
*      and orientation are still modelled, but not squash or shear -
*      the units of X and Y have to be the same.
*
*  2)  For NC=4, NP must be at least 2.  For NC=6, NP must be at
*      least 3.
*
*  3)  The model is returned in the array COEFFS.  Naming the
*      elements of COEFFS as follows:
*
*                  COEFFS(1) = A
*                  COEFFS(2) = B
*                  COEFFS(3) = C
*                  COEFFS(4) = D
*                  COEFFS(5) = E
*                  COEFFS(6) = F
*
*      the model is:
*
*            XE = A + B*XM + C*YM
*            YE = D + E*XM + F*YM
*
*      For the "solid body rotation" option (ITYPE=4), the
*      magnitudes of B and F, and of C and E, are equal.  The
*      signs of these coefficients depend on whether there is a
*      sign reversal between XE,YE and XM,YM;  fits are performed
*      with and without a sign reversal and the best one chosen.
*
*  4)  Error status values J=-1 and -2 leave COEFFS unchanged;
*      if J=-3 COEFFS may have been changed.
*
*  See also sla_PXY, sla_INVF, sla_XY2XY, sla_DCMPF
*
*  Called:  sla_DMAT, sla_DMXV
*
*  P.T.Wallace   Starlink   11 February 1991
*
*  Copyright (C) 1995 Rutherford Appleton Laboratory
*		converted to c++ by A. Shoup, 9/7/07
*/

	  static int I, JSTAT, IW[4];
	  static double P,SXE,SXEXM,SXEYM,SYE,SYEYM,SYEXM,SXM,
		   SYM,SXMXM,SXMYM,SYMYM,XE,YE,
		   XM,YM,V[4],DM4[4][4],DET;

//  Preset the status

      *J=0;

//  Float the number of samples

	  P = ((double) NP);

//  Check ITYPE


	  if (ITYPE != 6) {
		  *J = -1;
		  return;
	  }

//     Six-coefficient linear model
//     ----------------------------

//     Check enough samples
	  
	  if (NP < 3) {
		  *J = -2;
		  return;
	  }

//     Form summations
	  
	  SXE = SXEXM = SXEYM = SYE = SYEYM = SYEXM = SXM = SYM = SXMXM = SXMYM = SYMYM = 0.0;
	  
	  for (I=0; I<NP; I++) {
		  XE = XYE[0][I];
		  YE = XYE[1][I];
		  XM = XYM[0][I];
		  YM = XYM[1][I];
		  SXE = SXE+XE;
		  SXEXM = SXEXM+XE*XM;
		  SXEYM = SXEYM+XE*YM;
		  SYE = SYE+YE;
		  SYEYM = SYEYM+YE*YM;
		  SYEXM = SYEXM+YE*XM;
		  SXM = SXM+XM;
		  SYM = SYM+YM;
		  SXMXM = SXMXM+XM*XM;
		  SXMYM = SXMYM+XM*YM;
		  SYMYM = SYMYM+YM*YM;
	  }

//	  Solve for A,B,C in  XE = A + B*XM + C*YM

	  V[0] = SXE;
	  V[1] = SXEXM;
	  V[2] = SXEYM;
	  DM4[0][0] = P;
	  DM4[0][1] = SXM;
	  DM4[0][2] = SYM;
	  DM4[1][0] = SXM;
	  DM4[1][1] = SXMXM;
	  DM4[1][2] = SXMYM;
	  DM4[2][0] = SYM;
	  DM4[2][1] = SXMYM;
	  DM4[2][2] = SYMYM;
	  sla_DMAT(3, DM4, V, &DET, &JSTAT, IW);
	  if (JSTAT == 0) {
		  for (I=0; I<3; I++)
			  COEFFS[I] = V[I];

//        Solve for D,E,F in  YE = D + E*XM + F*YM
		  
		  V[0] = SYE;
		  V[1] = SYEXM;
		  V[2] = SYEYM;
		  sla_DMXV(DM4, V, &COEFFS[3]);

	  } else {

//        No 6-coefficient solution possible

		  *J = -3;
	  }
}


void sla_DMAT(int N, double A[4][4], double Y[4], double *D, int *JF, int IW[4]) {

/*
*     - - - - -
*      D M A T
*     - - - - -
*
*  Matrix inversion & solution of simultaneous equations
*  (double precision)
*
*  For the set of n simultaneous equations in n unknowns:
*     A.Y = X
*
*  where:
*     A is a non-singular N x N matrix
*     Y is the vector of N unknowns
*     X is the known vector
*
*  DMATRX computes:
*     the inverse of matrix A
*     the determinant of matrix A
*     the vector of N unknowns
*
*  Arguments:
*
*     symbol  type   dimension           before              after
*
*       N      i                    no. of unknowns       unchanged
*       A      d      (N,N)             matrix             inverse
*       Y      d       (N)              vector            solution
*       D      d                           -             determinant
*     * JF     i                           -           singularity flag
*       IW     i       (N)                 -              workspace
*
*  *  JF is the singularity flag.  If the matrix is non-singular,
*    JF=0 is returned.  If the matrix is singular, JF=-1 & D=0D0 are
*    returned.  In the latter case, the contents of array A on return
*    are undefined.
*
*  Algorithm:
*     Gaussian elimination with partial pivoting.
*
*  Speed:
*     Very fast.
*
*  Accuracy:
*     Fairly accurate - errors 1 to 4 times those of routines optimized
*     for accuracy.
*
*  P.T.Wallace   Starlink   7 February 1995
*
*  Copyright (C) 1995 Rutherford Appleton Laboratory
*/

#define SFA 1.0e-20

	static int K, IMX, I, J, KI, NP1MK;
	static double AMX, T, AKK, YK, AIK;

	*JF = 0;
	*D=1.0;
	for (K=0; K<N; K++) {
		AMX =  fabs(A[K][K]);
		IMX = K;
		if (K != N) {
			for (I=K+1; I<N; I++) {
				T = fabs(A[I][K]);
				if (T > AMX) {
					AMX = T;
					IMX = I;
				}
			}
		}
		if (AMX < SFA) {
			*JF = -1;
		} else {
			if (IMX != K) {
				for (J=0; J<N; J++) {
					T = A[K][J];
					A[K][J] = A[IMX][J];
					A[IMX][J] = T;
				}
				T = Y[K];
				Y[K] = Y[IMX];
				Y[IMX] = T;
				*D = -*D;
			}
			IW[K] = IMX;
			AKK = A[K][K];
            *D = *D*AKK;
			if (fabs(*D) < SFA) {
				*JF = -1;
			} else {
				AKK = 1.0/AKK;
				A[K][K] = AKK;
				for (J=0; J<N; J++)
                  if (J != K)
					  A[K][J] = A[K][J]*AKK;
				YK = Y[K]*AKK;
				Y[K] = YK;
				for (I=0; I<N; I++) {
					AIK = A[I][K];
					if (I != K) {
						for (J=0; J<N; J++)
							if (J != K)
								A[I][J] = A[I][J]-AIK*A[K][J];
						Y[I] = Y[I]-AIK*YK;
					}
				}
				for (I=0; I<N; I++)
					if (I != K)
						A[I][K] = -A[I][K]*AKK;
			}
		}
	}
	if (*JF != 0) {
		*D = 0.0;
	} else {
		for (K=0; K<N; K++) {
			NP1MK = N-1 - K;
			KI = IW[NP1MK];
			if (NP1MK != KI) {
				for (I=0; I<N; I++) {
					T = A[I][NP1MK];
					A[I][NP1MK] = A[I][KI];
					A[I][KI] = T;
				}
			}
		}
	}

}

void sla_DMXV(double DM[4][4], double VA[3], double VB[3]) {

/*
*     - - - - -
*      D M X V
*     - - - - -
*
*  Performs the 3-D forward unitary transformation:
*
*     vector VB = matrix DM * vector VA
*
*  (double precision)
*
*  Given:
*     DM       dp(3,3)    matrix
*     VA       dp(3)      vector
*
*  Returned:
*     VB       dp(3)      result vector
*
*  P.T.Wallace   Starlink   March 1986
*
*  Copyright (C) 1995 Rutherford Appleton Laboratory
*/


	static int I, J;
	static double W, VW[3];

//  Matrix DM * vector VA -> vector VW

	for (J=0; J<3; J++) {
		W = 0.0;
		for (I=0; I<3; I++)
            W = W+DM[J][I]*VA[I];
		VW[J] = W;
	}

//  Vector VW -> vector VB

	for (J=0; J<3; J++)
         VB[J] = VW[J];

}

}