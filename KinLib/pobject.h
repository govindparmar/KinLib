#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "pvector.h"

typedef double FORCE;
typedef double DISTANCE;

typedef struct _OBJECT
{
	double mass;
	double xpos;
	double ypos;
	struct _VECTOR velocity;
} OBJECT, *POBJECT;

OBJECT __cdecl centerMass(int N, ...);