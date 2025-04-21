#pragma once
#include <jni.h>

class CObject
{
public:
	CObject() : m_Object(NULL) {}
	CObject(jobject object) : m_Object(object) {}

	jobject GetObj()		{ return m_Object; }
	bool	isValid()		{ return m_Object ? true : false; }


private:
	jobject m_Object;
};