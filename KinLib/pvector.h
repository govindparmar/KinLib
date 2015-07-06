#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
typedef struct _VECTOR
{
	double mag;
	double dir;
} VECTOR, *PVECTOR;


VECTOR __stdcall addPerpVecs(VECTOR v1, VECTOR v2);
int __stdcall arePerpV(VECTOR v1, VECTOR v2);
VECTOR __stdcall addVectorsG(VECTOR v1, VECTOR v2);
double __cdecl fsign(double _X);
VECTOR __stdcall multScalar(VECTOR v, double s);
double __stdcall dotProduct(VECTOR v1, VECTOR v2);