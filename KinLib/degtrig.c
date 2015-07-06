#include "degtrig.h"

double d2r(double d)
{
	return d * M_PI / 180.0;
}

double r2d(double r)
{
	return r * 180.0 / M_PI;
}

double dcos(double _X)
{
	return cos(d2r(_X));
}

double dsin(double _X)
{
	return sin(d2r(_X));
}

double dtan(double _X)
{
	return tan(d2r(_X));
}

double dacos(double _X)
{
	return r2d(acos(_X));
}

double dasin(double _X)
{
	return r2d(asin(_X));
}

double datan(double _X)
{
	return r2d(atan(_X));
}