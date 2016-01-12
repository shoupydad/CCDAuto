
#include <math.h>

void sla_DMAT(int N, double A[4][4], double Y[4], double D, int JF, int IW[4]) {

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

#define SFA 1.0d-20

	int K, IMX, I, J, NP1MK, KI;
	double AMX, T, AKK, YK AIK;

	JF = 0;
	D=1.0;
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
			JF = -1;
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
				D = -D;
			}
			IW[K] = IMX;
			AKK = A[K][K];
            D = D*AKK;
			if (fabs(D) < SFA) {
				JF = -1;
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
	if (JF != 0)
		D=0.0;
	else {
		for (K=0; K<N; K++) {
			NP1MK = N+1-K;
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
