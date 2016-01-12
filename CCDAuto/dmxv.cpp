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


	int I, J;
	double W, VW[3];

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