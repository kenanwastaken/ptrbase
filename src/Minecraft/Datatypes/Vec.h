#pragma once
#include <jni.h>

class Vec3i
{
public:
	Vec3i(jint x, jint y, jint z) : posX(x), posY(y), posZ(z) {};

	jint GetX() { return posX; };
	jint GetY() { return posY; };
	jint GetZ() { return posZ; };
private:
	jint posX;
	jint posY;
	jint posZ;
};

class Vec3d
{
public:
	Vec3d(jdouble x, jdouble y, jdouble z) : posX(x), posY(y), posZ(z) {};
	Vec3d(Vec3i vec3i) : posX(vec3i.GetX()), posY(vec3i.GetY()), posZ(vec3i.GetZ()) {};

	jdouble GetX() { return posX; };
	jdouble GetY() { return posY; };
	jdouble GetZ() { return posZ; };
private:
	jdouble posX;
	jdouble posY;
	jdouble posZ;
};