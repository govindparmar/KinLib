// perpvec.c: Contains the methods for arithmetic and computation of perpendicular vectors

#include "pvector.h"
#include "degtrig.h"
// verifies that two vectors are perpendicular to each other.
// ret: 1 = are perpendicular; 0 = are not
// simple arithmetic on the directions
// since two vectors are perpendicular if |a|*|b|*theta==0, if theta==90 then cos(90)=0; the equation is guaranteed to be 0 - no need to compute the full product in that case
// otherwise, perform the full multiplication equation and return 1 or 0 as appropriate
int __stdcall arePerpV(VECTOR v1, VECTOR v2)
{
	double d1 = fabs(v1.dir);
	double d2 = fabs(v2.dir);
	// optimization: precompute this result because it is used twice later
	double dist = fabs(d2 - d1);
	double degdiffZ = dcos(dist);
	if (dist == 90.0)
	{
		return 1;
	}
	if ( (v1.mag*v2.mag*degdiffZ) == 0.0)
	{
		return 1;
	}
	return 0;
}

// Performs addition of two vectors that are perpendicular to one another.
// Uses SOH-CAH-TOA rule to determine the non-right angle of the sum vector (inv tangent of O/A)
// Where v1 is the vector OPPOSITE to the resultant angle, and v2 is the vector ADJACENT to the resultant angle
VECTOR __stdcall addPerpVecs(VECTOR v1, VECTOR v2)
{
	VECTOR vRet;
	double m1 = v1.mag;
	double m2 = v2.mag;
	double mRet = sqrt((m1*m1) + (m2*m2));
	double O = (v1.mag);
	double A = (v2.mag);
	ZeroMemory(&vRet, sizeof(VECTOR));
	vRet.mag = mRet;
	vRet.dir = datan(O / A);
	return vRet;
}
