#include "CMethod.h"
#include "../../Java/JVM/JVM.h"

jboolean CMethod::GetBoolean()
{
	if(m_Class.isValid())
		return JVM::GetInstance().m_Env->CallStaticBooleanMethod(m_Class.GetClass(), m_Method);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->CallBooleanMethod(m_Object.GetObj(), m_Method);

	return JNI_FALSE;
}

CObject CMethod::GetObj()
{
	if (m_Class.isValid())
		return CObject(JVM::GetInstance().m_Env->CallStaticObjectMethod(m_Class.GetClass(), m_Method));
	else if (m_Object.isValid())
		return CObject(JVM::GetInstance().m_Env->CallObjectMethod(m_Object.GetObj(), m_Method));

	return CObject(jobject(NULL));
}

CObject CMethod::GetObj(jvalue* args)
{
	if (m_Class.isValid())
		return CObject(JVM::GetInstance().m_Env->CallStaticObjectMethodA(m_Class.GetClass(), m_Method, args));
	else if (m_Object.isValid())
		return CObject(JVM::GetInstance().m_Env->CallObjectMethodA(m_Object.GetObj(), m_Method, args));

	return CObject(jobject(NULL));
}

jint CMethod::GetInt()
{
	if (m_Class.isValid())
		return JVM::GetInstance().m_Env->CallStaticIntMethod(m_Class.GetClass(), m_Method);
	else if (m_Object.isValid())
		return JVM::GetInstance().m_Env->CallIntMethod(m_Object.GetObj(), m_Method);

	return 0;
}

jstring CMethod::GetString()
{
	if (m_Class.isValid())
		return (jstring)JVM::GetInstance().m_Env->CallStaticObjectMethod(m_Class.GetClass(), this->m_Method);
	else if (m_Object.isValid())
		return (jstring)JVM::GetInstance().m_Env->CallObjectMethod(m_Object.GetObj(), this->m_Method);

	return jstring();
}