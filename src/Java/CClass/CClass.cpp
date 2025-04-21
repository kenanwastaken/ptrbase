#include "CClass.h"
#include "../JVM/JVM.h"

CClass::CClass(const char* name)
{
	m_Class = JVM::GetInstance().FindClass(name).GetClass();
}

jfieldID CClass::GetStaticFieldID(const char* name, const char* signature)
{
	return JVM::GetInstance().m_Env->GetStaticFieldID(m_Class, name, signature);
}

jfieldID CClass::GetFieldID(const char* name, const char* signature)
{
	return JVM::GetInstance().m_Env->GetFieldID(m_Class, name, signature);
}

jmethodID CClass::GetMethodID(const char* name, const char* signature)
{
	return JVM::GetInstance().m_Env->GetMethodID(m_Class, name, signature);
}
