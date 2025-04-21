#pragma once
#include <jni/jni.h>
#include "../CClass/CClass.h"
#include "../CObject/CObject.h"

class CMethod
{
public:
	CMethod(CClass clazz, jmethodID methodid) : m_Class(clazz), m_Method(methodid) {}
	CMethod(CObject object, jmethodID methodid) : m_Object(object), m_Method(methodid) {}

	bool isValid() { return ((m_Class.isValid() || m_Object.isValid()) && m_Method); }

	jstring		GetString();
	jboolean	GetBoolean();
	jint		GetInt();
	CObject		GetObj();
	CObject		GetObj(jvalue* args);
private:
	CClass m_Class = CClass(jclass(NULL));
	CObject m_Object = CObject(jobject(NULL));
	jmethodID m_Method = NULL;
};