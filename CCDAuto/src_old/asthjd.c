#include	<math.h>


void ConvertJDtoHJD(double ra, double dec, double jd, double *lt, double *hjd);
void ast_coord(double ao, double bo, double ap, double bp, double a1,
	       double b1, double *a2, double *b2);


int main()
{

  double jd, hjd, ra, dec, lt;

  printf("Enter jd ra dec: ");
  scanf("%lf %lf %lf", &jd, &ra, &dec);
  printf("\n");
  ast_jd_to_hjd(ra, dec, jd, &lt, &hjd);

  printf("HJD: %lf, lt: %lf (%lf)\n", hjd, lt, lt*86400.0);

  exit(0);
}



#define PI 3.141592654
#define HALFPI 1.570796327

// ConvertJDtoHJD -- Helocentric Julian Day from UT Julian date

void ConvertJDtoHJD(double ra, double dec, double jd, double *lt, double *hjd)
{
  /*  double	ra;    Right ascension of observation (hours)
      double	dec;   Declination of observation (degrees)
      double	jd;    Geocentric Julian date of observation
      double	lt;    Light travel time in seconds
      double	hjd;   Helocentric Julian Day
  */

  double t, manom, lperi, oblq, eccen, tanom, slong, r, d, l, b, rsun;
  // JD is the geocentric Julian date.
  // T is the number of Julian centuries since J1900.

  t = (jd - 2415020.0) / 36525.0;

  // MANOM is the mean anomaly of the Earth's orbit (degrees)
  // LPERI is the mean longitude of perihelion (degrees)
  // OBLQ is the mean obliquity of the ecliptic (degrees)
  // ECCEN is the eccentricity of the Earth's orbit (dimensionless)

  manom = 358.47583 +
    t * (35999.04975 - t * (0.000150 + t * 0.000003));
  lperi = 101.22083 +
    t * (1.7191733 + t * (0.000453 + t * 0.000003));
  oblq = 23.452294 -
    t * (0.0130125 + t * (0.00000164 - t * 0.000000503));
  eccen = 0.01675104 - t * (0.00004180 + t * 0.000000126);

  // Convert to principle angles

  manom = fmod(manom,360.0);
  lperi = fmod(lperi,360.0);

  // Convert to radians

  r = ra * 2.0*PI/24.0;
  d = dec * 2.0*PI/360.0;
  manom = manom * 2.0*PI/360.0;
  lperi = lperi * 2.0*PI/360.0;
  oblq = oblq * 2.0*PI/360.0;

  // TANOM is the true anomaly (approximate formula) (radians)

  tanom = manom + (2 * eccen - 0.25 * eccen*eccen*eccen) * sin (manom) +
    1.25 * eccen*eccen * sin (2 * manom) +
    13./12. * eccen*eccen*eccen * sin (3 * manom);

  // SLONG is the true longitude of the Sun seen from the Earth (radians)

  slong = lperi + tanom + PI;

  // L and B are the longitude and latitude of the star in the orbital
  // plane of the Earth (radians)

  ast_coord(0.0, 0.0, -HALFPI, HALFPI - oblq, r, d, &l, &b);

  // R is the distance to the Sun.

  rsun = (1. - eccen*eccen) / (1. + eccen * cos(tanom));

  // LT is the light travel difference to the Sun.

  *lt = -0.005770 * rsun * cos(b) * cos(l - slong);
  *hjd = jd + *lt;

  return;
}


// AST_COORD -- Convert spherical coordinates to new system.

// This procedure converts the longitude-latitude coordinates (a1, b1)
// of a point on a sphere into corresponding coordinates (a2, b2) in a
// different coordinate system that is specified by the coordinates of its
// origin (ao, bo).  The range of a2 will be from -pi to pi.

void ast_coord(double ao, double bo, double ap, double bp, double a1,
	       double b1, double *a2, double *b2)
{

  /* 
     double ao, bo;     Origin of new coordinates (radians)
     double ap, bp;	Pole of new coordinates (radians)
     double a1, b1;	Coordinates to be converted (radians)
     double a2, b2;	Converted coordinates (radians)
  */

  double sao, cao, sbo, cbo, sbp, cbp;
  double x, y, z, xp, yp, zp, temp;

  x = cos(a1) * cos(b1);
  y = sin(a1) * cos(b1);
  z = sin(b1);
  xp = cos(ap) * cos(bp);
  yp = sin(ap) * cos(bp);
  zp = sin(bp);

  // Rotate the origin about z.

  sao = sin(ao);
  cao = cos(ao);
  sbo = sin(bo);
  cbo = cos(bo);
  temp = -xp * sao + yp * cao;
  xp = xp * cao + yp * sao;
  yp = temp;
  temp = -x * sao + y * cao;
  x = x * cao + y * sao;
  y = temp;

  // Rotate the origin about y.

  temp = -xp * sbo + zp * cbo;
  xp = xp * cbo + zp * sbo;
  zp = temp;
  temp = -x * sbo + z * cbo;
  x = x * cbo + z * sbo;
  z = temp;

  // Rotate pole around x.

  sbp = zp;
  cbp = yp;
  temp = y * cbp + z * sbp;
  y = y * sbp - z * cbp;
  z = temp;

  // Final angular coordinates.

  *a2 = atan2(y, x);
  *b2 = asin(z);

  return;
}
