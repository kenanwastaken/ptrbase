#pragma once
#include "../CClass/CClass.h"
#include "../CObject/CObject.h"

class CField
{
public:
	CField(CClass clazz, jfieldID field) : m_Class(clazz), m_Field(field) {};
	CField(CObject obj, jfieldID field) : m_Object(obj), m_Field(field) {};

	bool isValid() { return (m_Class.isValid() && m_Field); }

	CObject		GetStaticObject();
	CObject		GetObject();

	jint		GetInt();
	void		SetInt(jint val);

	jdouble		GetDouble();
	void		SetDouble(jdouble val);

	jfloat		GetFloat();
	void		SetFloat(jfloat val);

	jboolean	GetBoolean();
	void		SetBoolean(jboolean val);

	jstring		GetString();
private:
	CClass m_Class = CClass(jclass(NULL));
	CObject m_Object = CObject(jobject(NULL));
	jfieldID m_Field = NULL;
};