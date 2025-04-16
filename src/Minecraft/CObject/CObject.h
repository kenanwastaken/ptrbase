#pragma once
#include <jvmti.h>

class CObject
{
public:
	CObject(jobject object) : m_Object(object) {};
	~CObject();

	jobject Obj();
private:
	jobject m_Object = nullptr;
};