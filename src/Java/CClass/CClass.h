#pragma once
#include <jni.h>

class CClass
{
public:
	CClass(jclass clazz) : m_Class(clazz) {}
	CClass(const char* name);

	jclass GetClass() { return m_Class; }

	bool isValid() { return m_Class ? true : false; }

	jfieldID GetStaticFieldID(const char* name, const char* signature);
	jfieldID GetFieldID(const char* name, const char* signature);

	jmethodID GetMethodID(const char* name, const char* signature);
private:
	jclass m_Class = NULL;
};