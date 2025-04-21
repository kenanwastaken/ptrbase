#include "CField.h"
#include "../JVM/JVM.h"
#include <iostream>

CObject CField::GetStaticObject()
{
	return JVM::GetInstance().m_Env->GetStaticObjectField(this->m_Class.GetClass(), this->m_Field);
}

CObject CField::GetObject()
{
	if (m_Class.isValid())
		return JVM::GetInstance().m_Env->GetStaticObjectField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->GetObjectField(this->m_Object.GetObj(), this->m_Field);

	return(CObject(jobject(NULL)));
}

jint CField::GetInt()
{
	if(m_Class.isValid())
		return JVM::GetInstance().m_Env->GetStaticIntField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->GetIntField(this->m_Object.GetObj(), this->m_Field);

	return NULL;
}

void CField::SetInt(jint val)
{
	if(m_Class.isValid())
		JVM::GetInstance().m_Env->SetStaticIntField(this->m_Class.GetClass(), this->m_Field, val);
	else if (m_Object.isValid())
		JVM::GetInstance().m_Env->SetIntField(this->m_Object.GetObj(), this->m_Field, val);
}

jdouble CField::GetDouble()
{
	if (m_Class.isValid())
		return JVM::GetInstance().m_Env->GetStaticDoubleField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->GetDoubleField(this->m_Object.GetObj(), this->m_Field);

	return -1;
}

void CField::SetDouble(jdouble val)
{
	if (m_Class.isValid())
		JVM::GetInstance().m_Env->SetStaticDoubleField(this->m_Class.GetClass(), this->m_Field, val);
	else if (m_Object.isValid())
		JVM::GetInstance().m_Env->SetDoubleField(this->m_Object.GetObj(), this->m_Field, val);
}

jfloat CField::GetFloat()
{
	if (m_Class.isValid())
		return JVM::GetInstance().m_Env->GetStaticFloatField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->GetFloatField(this->m_Object.GetObj(), this->m_Field);

	return -1;
}

void CField::SetFloat(jfloat val)
{
	if (m_Class.isValid())
		JVM::GetInstance().m_Env->SetStaticFloatField(this->m_Class.GetClass(), this->m_Field, val);
	else if (m_Object.isValid())
		JVM::GetInstance().m_Env->SetFloatField(this->m_Object.GetObj(), this->m_Field, val);
}

jboolean CField::GetBoolean()
{
	if (m_Class.isValid())
		return JVM::GetInstance().m_Env->GetStaticBooleanField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->GetBooleanField(this->m_Object.GetObj(), this->m_Field);

	return false;
}

void CField::SetBoolean(jboolean val)
{
	if (m_Class.isValid())
		JVM::GetInstance().m_Env->SetStaticBooleanField(this->m_Class.GetClass(), this->m_Field, val);
	else if (m_Object.isValid())
		JVM::GetInstance().m_Env->SetBooleanField(this->m_Object.GetObj(), this->m_Field, val);
}

jstring CField::GetString()
{
	if (m_Class.isValid())
		return (jstring)JVM::GetInstance().m_Env->GetObjectField(this->m_Class.GetClass(), this->m_Field);
	else if (m_Object.isValid())
		return (jstring)JVM::GetInstance().m_Env->GetObjectField(this->m_Object.GetObj(), this->m_Field);

	return jstring();
}
