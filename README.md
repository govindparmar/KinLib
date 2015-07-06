# KinLib
Windows DLL; Contains methods for various 2D kinematics, to assist with creation of games and whatnot.

arePerpV(VECTOR, VECTOR) - determines whether two vectors are perpendicular to one another.
addPerpVecs(VECTOR, VECTOR) - adds two perpendicular vectors using the Pythagorean theorem.
addVectorsG(VECTOR, VECTOR) - adds two generic (i.e. not necessarily perpendicular) vectors using the laws of Sines and Cosines.
centerMass(int, ...) - given an integer N followed by N objects, computes the centroid (i.e. center of mass) of all the objects.
collideObjectsStick(OBJECT*, OBJECT*) - given two pointers to objects, updates their velocity assuming they collided and stuck together
collideObjectsBounce(OBJECT*, OBJECT*) - given two pointers to objects, updates their velocities assuming they collided and ricocheted off each other
fsign(double) - returns -1.0, 0.0, or 1.0 corresponding to the sign of the number passed as an argument.
dotProduct(VECTOR, VECTOR) - computes the dot product of two vectors
multScalar(VECTOR, double) - multiplies a vector by a scalar quantity, modifying its magnitude but keeping its direction intact
