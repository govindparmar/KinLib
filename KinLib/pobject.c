#include "pobject.h"

// Calculates the center of mass of a number of objects.
// N: number of objects
// ...: N OBJECT structs
// OUT: centroid object
// Notes:
// *needs* to be CDECL because of unknown argument number
OBJECT __cdecl centerMass(int N, ...)
{
	OBJECT centroid = { 0 }, tmp;
	va_list vl;
	int i;
	
	va_start(vl, N);
	
	for (i = 1; i < N; i++)
	{
		tmp = va_arg(vl, OBJECT);
		centroid.xpos += (tmp.xpos * tmp.mass);
		centroid.ypos += (tmp.ypos * tmp.mass);
		centroid.mass += tmp.mass;
	}

	va_end(vl);
	
	centroid.xpos /= (double)N;
	centroid.ypos /= (double)N;
	
	return centroid;
}

// Two adhesive objects collide and stick together.
VOID __stdcall collideObjectsStick(OBJECT *o1, OBJECT *o2)
{
	VECTOR m1, m2, p, vF;

	// parallel moving objects: no possibility of collision
	if (o1->velocity.dir == o2->velocity.dir)
	{
		return;
	}
	
	m1 = multScalar(o1->velocity, o1->mass);
	m2 = multScalar(o2->velocity, o2->mass);
	p = addVectorsG(m1, m2);
	vF = multScalar(p, 1 / (o1->mass + o2->mass));
	o1->velocity = vF;
	o2->velocity = vF;
}

// Two inadhesive objects collide and bounce apart.
VOID __stdcall collideObjectsBounce(OBJECT *o1, OBJECT *o2)
{
	VECTOR m1, m2, p1, p2;

	// parallel moving objects: no possibility of collision
	if (o1->velocity.dir == o2->velocity.dir)
		return;

	m1 = multScalar(o1->velocity, o1->mass);
	m2 = multScalar(o2->velocity, o2->mass);

	// this part is somewhat arbitrary. 
	// because of the law of conservation of momentum, the only requirement is that the two resultant momentums have the same sum as the sum of the two original momentums.
	// i'm just going with +- 5 degrees for both objects
	p1.dir = m1.dir;
	p1.mag = m1.mag - 5;

	p2.dir = m2.dir;
	p2.mag = m2.mag + 5;

	o1->velocity = p1;
	o2->velocity = p2;

}