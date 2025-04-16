#pragma once
#include <jni.h>

class CClass
{
public:
	CClass(const char* name);
	CClass(jclass clazz) : cachedClass(clazz) {};
	~CClass();

	jclass Class();
private:
	jclass cachedClass;
};