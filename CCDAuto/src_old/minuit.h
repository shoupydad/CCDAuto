/*
 *  Interface to minuit using cfortran.h
 *
 *  Edit history:
 *  G.Folger  12-Dec-94  change some to use ROUTINE for passing fcn/futil
 */

//PROTOCCALLSFFUN1(LOGICAL,MNUNPT,mnunpt,BYTE)
//#define MNUNPT(A2)  CCALLSFFUN1(MNUNPT,mnunpt,BYTE,A2)

PROTOCCALLSFSUB2(MINUIT,minuit,ROUTINE,ROUTINE)
#define MINUIT(A1,A2)  CCALLSFSUB2(MINUIT,minuit,ROUTINE,ROUTINE,A1,A2)

PROTOCCALLSFSUB2(MNAMIN,mnamin,DOUBLE,DOUBLE)
#define MNAMIN(A1,A2)  CCALLSFSUB2(MNAMIN,mnamin,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB7(MNBINS,mnbins,DOUBLE,DOUBLE,INT,PDOUBLE,PDOUBLE,PINT,PDOUBLE)
#define MNBINS(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNBINS,mnbins,DOUBLE,DOUBLE,INT,PDOUBLE,PDOUBLE,PINT,PDOUBLE,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB4(MNCALF,mncalf,DOUBLE,DOUBLEV,PDOUBLE,DOUBLE)
#define MNCALF(A1,A2,A3,A4)  CCALLSFSUB4(MNCALF,mncalf,DOUBLE,DOUBLEV,PDOUBLE,DOUBLE,A1,A2,A3,A4)

PROTOCCALLSFSUB0(MNCLER,mncler)
#define MNCLER() CCALLSFSUB0(MNCLER,mncler)

PROTOCCALLSFSUB5(MNCNTR,mncntr,DOUBLE,INT,INT,PINT,DOUBLE)
#define MNCNTR(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNCNTR,mncntr,DOUBLE,INT,INT,PINT,DOUBLE,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB4(MNCOMD,mncomd,ROUTINE,STRING,PINT,ROUTINE)
#define MNCOMD(A1,A2,A3,A4)  CCALLSFSUB4(MNCOMD,mncomd,ROUTINE,STRING,PINT,ROUTINE,A1,A2,A3,A4)

PROTOCCALLSFSUB8(MNCONT,mncont,ROUTINE,INT,INT,INT,PDOUBLE,PDOUBLE,PINT,ROUTINE)
#define MNCONT(A1,A2,A3,A4,A5,A6,A7,A8)  CCALLSFSUB8(MNCONT,mncont,ROUTINE,INT,INT,INT,PDOUBLE,PDOUBLE,PINT,ROUTINE,A1,A2,A3,A4,A5,A6,A7,A8)

PROTOCCALLSFSUB9(MNCRCK,mncrck,STRING,INT,PSTRING,PINT,INT,PDOUBLE,PINT,PINT,INT)
#define MNCRCK(A1,A2,A3,A4,A5,A6,A7,A8,A9)  CCALLSFSUB9(MNCRCK,mncrck,STRING,INT,PSTRING,PINT,INT,PDOUBLE,PINT,PINT,INT,A1,A2,A3,A4,A5,A6,A7,A8,A9)

PROTOCCALLSFSUB4(MNCROS,mncros,DOUBLE,PDOUBLE,PINT,DOUBLE)
#define MNCROS(A1,A2,A3,A4)  CCALLSFSUB4(MNCROS,mncros,DOUBLE,PDOUBLE,PINT,DOUBLE,A1,A2,A3,A4)

PROTOCCALLSFSUB2(MNCUVE,mncuve,DOUBLE,DOUBLE)
#define MNCUVE(A1,A2)  CCALLSFSUB2(MNCUVE,mncuve,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNDERI,mnderi,DOUBLE,DOUBLE)
#define MNDERI(A1,A2)  CCALLSFSUB2(MNDERI,mnderi,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB3(MNDXDI,mndxdi,DOUBLE,INT,PDOUBLE)
#define MNDXDI(A1,A2,A3)  CCALLSFSUB3(MNDXDI,mndxdi,DOUBLE,INT,PDOUBLE,A1,A2,A3)

PROTOCCALLSFSUB7(MNEIG,mneig,PDOUBLE,INT,INT,INT,PDOUBLE,DOUBLE,PINT)
#define MNEIG(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNEIG,mneig,PDOUBLE,INT,INT,INT,PDOUBLE,DOUBLE,PINT,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB2(MNEMAT,mnemat,PDOUBLE,INT)
#define MNEMAT(A1,A2)  CCALLSFSUB2(MNEMAT,mnemat,PDOUBLE,INT,A1,A2)

PROTOCCALLSFSUB5(MNERRS,mnerrs,INT,PDOUBLE,PDOUBLE,PDOUBLE,PDOUBLE)
#define MNERRS(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNERRS,mnerrs,INT,PDOUBLE,PDOUBLE,PDOUBLE,PDOUBLE,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB5(MNEVAL,mneval,DOUBLE,DOUBLE,PDOUBLE,PINT,DOUBLE)
#define MNEVAL(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNEVAL,mneval,DOUBLE,DOUBLE,PDOUBLE,PINT,DOUBLE,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB6(MNEXCM,mnexcm,ROUTINE,STRING,DOUBLEV,INT,PINT,ROUTINE)
#define MNEXCM(A1,A2,A3,A4,A5,A6)  CCALLSFSUB6(MNEXCM,mnexcm,ROUTINE,STRING,DOUBLEV,INT,PINT,ROUTINE,A1,A2,A3,A4,A5,A6)

PROTOCCALLSFSUB1(MNEXIN,mnexin,PDOUBLE)
#define MNEXIN(A1)  CCALLSFSUB1(MNEXIN,mnexin,PDOUBLE,A1)

PROTOCCALLSFSUB2(MNFIXP,mnfixp,INT,PINT)
#define MNFIXP(A1,A2)  CCALLSFSUB2(MNFIXP,mnfixp,INT,PINT,A1,A2)

PROTOCCALLSFSUB1(MNFREE,mnfree,INT)
#define MNFREE(A1)  CCALLSFSUB1(MNFREE,mnfree,INT,A1)

PROTOCCALLSFSUB2(MNGRAD,mngrad,DOUBLE,DOUBLE)
#define MNGRAD(A1,A2)  CCALLSFSUB2(MNGRAD,mngrad,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNHELP,mnhelp,STRING,INT)
#define MNHELP(A1,A2)  CCALLSFSUB2(MNHELP,mnhelp,STRING,INT,A1,A2)

PROTOCCALLSFSUB2(MNHES1,mnhes1,DOUBLE,DOUBLE)
#define MNHES1(A1,A2)  CCALLSFSUB2(MNHES1,mnhes1,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNHESS,mnhess,DOUBLE,DOUBLE)
#define MNHESS(A1,A2)  CCALLSFSUB2(MNHESS,mnhess,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNIMPR,mnimpr,DOUBLE,DOUBLE)
#define MNIMPR(A1,A2)  CCALLSFSUB2(MNIMPR,mnimpr,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB1(MNINEX,mninex,DOUBLEV)
#define MNINEX(A1)  CCALLSFSUB1(MNINEX,mninex,DOUBLEV,A1)

PROTOCCALLSFSUB3(MNINIT,mninit,INT,INT,INT)
#define MNINIT(A1,A2,A3)  CCALLSFSUB3(MNINIT,mninit,INT,INT,INT,A1,A2,A3)

PROTOCCALLSFSUB2(MNINPU,mninpu,INT,PINT)
#define MNINPU(A1,A2)  CCALLSFSUB2(MNINPU,mninpu,INT,PINT,A1,A2)

PROTOCCALLSFSUB2(MNINTR,mnintr,ROUTINE,ROUTINE)
#define MNINTR(A1,A2)  CCALLSFSUB2(MNINTR,mnintr,ROUTINE,ROUTINE,A1,A2)

PROTOCCALLSFSUB2(MNLIMS,mnlims,DOUBLE,DOUBLE)
#define MNLIMS(A1,A2)  CCALLSFSUB2(MNLIMS,mnlims,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB7(MNLINE,mnline,DOUBLE,DOUBLEV,DOUBLE,DOUBLEV,DOUBLE,DOUBLE,DOUBLE)
#define MNLINE(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNLINE,mnline,DOUBLE,DOUBLEV,DOUBLE,DOUBLEV,DOUBLE,DOUBLE,DOUBLE,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB1(MNMATU,mnmatu,INT)
#define MNMATU(A1)  CCALLSFSUB1(MNMATU,mnmatu,INT,A1)

PROTOCCALLSFSUB2(MNMIGR,mnmigr,DOUBLE,DOUBLE)
#define MNMIGR(A1,A2)  CCALLSFSUB2(MNMIGR,mnmigr,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNMNOS,mnmnos,DOUBLE,DOUBLE)
#define MNMNOS(A1,A2)  CCALLSFSUB2(MNMNOS,mnmnos,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB6(MNMNOT,mnmnot,DOUBLE,INT,INT,DOUBLE,DOUBLE,DOUBLE)
#define MNMNOT(A1,A2,A3,A4,A5,A6)  CCALLSFSUB6(MNMNOT,mnmnot,DOUBLE,INT,INT,DOUBLE,DOUBLE,DOUBLE,A1,A2,A3,A4,A5,A6)

PROTOCCALLSFSUB7(MNPARM,mnparm,INT,STRING,DOUBLE,DOUBLE,PDOUBLE,PDOUBLE,PINT)
#define MNPARM(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNPARM,mnparm,INT,STRING,DOUBLE,DOUBLE,PDOUBLE,PDOUBLE,PINT,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB2(MNPARS,mnpars,BYTE,PINT)
#define MNPARS(A1,A2)  CCALLSFSUB2(MNPARS,mnpars,BYTE,PINT,A1,A2)

PROTOCCALLSFSUB5(MNPFIT,mnpfit,DOUBLEV,DOUBLEV,INT,PDOUBLE,PDOUBLE)
#define MNPFIT(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNPFIT,mnpfit,DOUBLEV,DOUBLEV,INT,PDOUBLE,PDOUBLE,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB3(MNPINT,mnpint,PDOUBLE,INT,PDOUBLE)
#define MNPINT(A1,A2,A3)  CCALLSFSUB3(MNPINT,mnpint,PDOUBLE,INT,PDOUBLE,A1,A2,A3)

PROTOCCALLSFSUB7(MNPLOT,mnplot,PDOUBLE,PDOUBLE,PSTRINGV,INT,INT,INT,INT)
#define MNPLOT(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNPLOT,mnplot,PDOUBLE,PDOUBLE,PSTRINGV,INT,INT,INT,INT,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB7(MNPOUT,mnpout,INT,PSTRING,PDOUBLE,PDOUBLE,PDOUBLE,PDOUBLE,PINT)
#define MNPOUT(A1,A2,A3,A4,A5,A6,A7)  CCALLSFSUB7(MNPOUT,mnpout,INT,PSTRING,PDOUBLE,PDOUBLE,PDOUBLE,PDOUBLE,PINT,A1,A2,A3,A4,A5,A6,A7)

PROTOCCALLSFSUB2(MNPRIN,mnprin,INT,DOUBLE)
#define MNPRIN(A1,A2)  CCALLSFSUB2(MNPRIN,mnprin,INT,DOUBLE,A1,A2)

PROTOCCALLSFSUB0(MNPSDF,mnpsdf)
#define MNPSDF() CCALLSFSUB0(MNPSDF,mnpsdf)

PROTOCCALLSFSUB5(MNRAZZ,mnrazz,DOUBLE,DOUBLEV,PDOUBLE,PINT,PINT)
#define MNRAZZ(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNRAZZ,mnrazz,DOUBLE,DOUBLEV,PDOUBLE,PINT,PINT,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB4(MNREAD,mnread,DOUBLE,INT,PINT,DOUBLE)
#define MNREAD(A1,A2,A3,A4)  CCALLSFSUB4(MNREAD,mnread,DOUBLE,INT,PINT,DOUBLE,A1,A2,A3,A4)

PROTOCCALLSFSUB2(MNRN15,mnrn15,PDOUBLE,PINT)
#define MNRN15(A1,A2)  CCALLSFSUB2(MNRN15,mnrn15,PDOUBLE,PINT,A1,A2)

PROTOCCALLSFSUB1(MNRSET,mnrset,INT)
#define MNRSET(A1)  CCALLSFSUB1(MNRSET,mnrset,INT,A1)

PROTOCCALLSFSUB0(MNSAVE,mnsave)
#define MNSAVE() CCALLSFSUB0(MNSAVE,mnsave)

PROTOCCALLSFSUB2(MNSCAN,mnscan,DOUBLE,DOUBLE)
#define MNSCAN(A1,A2)  CCALLSFSUB2(MNSCAN,mnscan,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNSEEK,mnseek,DOUBLE,DOUBLE)
#define MNSEEK(A1,A2)  CCALLSFSUB2(MNSEEK,mnseek,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB2(MNSET,mnset,DOUBLE,DOUBLE)
#define MNSET(A1,A2)  CCALLSFSUB2(MNSET,mnset,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB1(MNSETI,mnseti,STRING)
#define MNSETI(A1)  CCALLSFSUB1(MNSETI,mnseti,STRING,A1)

PROTOCCALLSFSUB2(MNSIMP,mnsimp,DOUBLE,DOUBLE)
#define MNSIMP(A1,A2)  CCALLSFSUB2(MNSIMP,mnsimp,DOUBLE,DOUBLE,A1,A2)

PROTOCCALLSFSUB6(MNSTAT,mnstat,PDOUBLE,PDOUBLE,PDOUBLE,PINT,PINT,PINT)
#define MNSTAT(A1,A2,A3,A4,A5,A6)  CCALLSFSUB6(MNSTAT,mnstat,PDOUBLE,PDOUBLE,PDOUBLE,PINT,PINT,PINT,A1,A2,A3,A4,A5,A6)

PROTOCCALLSFSUB2(MNSTIN,mnstin,BYTE,PINT)
#define MNSTIN(A1,A2)  CCALLSFSUB2(MNSTIN,mnstin,BYTE,PINT,A1,A2)

PROTOCCALLSFSUB2(MNTINY,mntiny,DOUBLE,PDOUBLE)
#define MNTINY(A1,A2)  CCALLSFSUB2(MNTINY,mntiny,DOUBLE,PDOUBLE,A1,A2)

PROTOCCALLSFSUB5(MNVERT,mnvert,PDOUBLE,INT,INT,INT,PINT)
#define MNVERT(A1,A2,A3,A4,A5)  CCALLSFSUB5(MNVERT,mnvert,PDOUBLE,INT,INT,INT,PINT,A1,A2,A3,A4,A5)

PROTOCCALLSFSUB3(MNWARN,mnwarn,BYTE,BYTE,BYTE)
#define MNWARN(A1,A2,A3)  CCALLSFSUB3(MNWARN,mnwarn,BYTE,BYTE,BYTE,A1,A2,A3)

PROTOCCALLSFSUB0(MNWERR,mnwerr)
#define MNWERR() CCALLSFSUB0(MNWERR,mnwerr)

PROTOCCALLSFSUB0(STAND,stand)
#define STAND() CCALLSFSUB0(STAND,stand)
