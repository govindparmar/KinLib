//genvec.c: contains methods for arithmetic on vectors that are not necessarily perpendicular.
#include "pvector.h"
#include "degtrig.h"
const double g_rdConv = 180.0 / M_PI;
const double g_dgConv = M_PI / 180.0;

VECTOR __stdcall multScalar(VECTOR v, double s)
{
	VECTOR vRet;
	ZeroMemory(&vRet, sizeof(VECTOR));
	
	vRet.dir = v.dir;
	vRet.mag = v.mag*s;
	
	return vRet;
}

double __stdcall dotProduct(VECTOR v1, VECTOR v2)
{
	double dRet = 0.0;
	double mx, mn;

	if (arePerpV(v1, v2)) return 0.0;
	
	mx = max(v1.dir, v2.dir);
	mn = min(v1.dir, v2.dir);

	dRet = v1.mag*v2.mag* dcos(mx-mn);

	return dRet;
}

VECTOR __stdcall addVectorsG(VECTOR v1, VECTOR v2)
{
	VECTOR vRet;
	
#ifdef _DEBUG
	// To hold messages for debugging info
	TCHAR mbBuf[256];
#endif
	double A = 0.0, b, c, aSq, mx, mn, ratio_a_sinA;
	ZeroMemory(&vRet, sizeof(VECTOR));

	if (arePerpV(v1, v2)) return addPerpVecs(v1, v2);

	
	// Law of Cosines:
	// (a^2)=(b^2)+(c^2)-2*b*c*cos(A)

	mx = max(v1.dir, v2.dir);
	mn = min(v1.dir, v2.dir);
	
	A = mx - mn;

	b = v1.mag;
	c = v2.mag;

	aSq = (b*b) + (c*c) - (2.0 * b * c * dcos(A));
	
	vRet.mag = sqrt(fabs(aSq));

	// Law of Sines:
	// a/sin(A) == b/sin(B) == c/sin(C)
	// working with the inverse fraction is easier (solving for sin(A)/a==sin(B)/b)

	ratio_a_sinA = dsin(A) / vRet.mag;
	vRet.dir = dasin(b*ratio_a_sinA);
	return vRet;
}