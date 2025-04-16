#include "JVM.h"

JVM::JVM()
{

}

bool JVM::Load()
{
	JNI_GetCreatedJavaVMs(&this->m_Vm, 1l, nullptr);

	this->m_Vm->GetEnv(reinterpret_cast<void**>(&this->m_Env), JNI_VERSION_20);
	this->m_Vm->AttachCurrentThread(reinterpret_cast<void**>(&this->m_Env), nullptr);
	this->m_Vm->GetEnv((void**)&this->m_tiEnv, JVMTI_VERSION_1_2);

	jclass lang = m_Env->FindClass("java/lang/Class");
	jmethodID getName = m_Env->GetMethodID(lang, "getName", "()Ljava/lang/String;");

	jclass* classes;
	jint amount;

	m_tiEnv->GetLoadedClasses(&amount, &classes);

	for (int i = 0; i < amount; i++)
	{
		jstring name = (jstring)m_Env->CallObjectMethod(classes[i], getName);
		const char* className = m_Env->GetStringUTFChars(name, 0);
		m_Env->ReleaseStringUTFChars(name, className);
		cachedClasses.emplace(std::make_pair(std::string(className), classes[i]));
	}

	return true;
}

jclass JVM::GetClass(std::string className)
{
	auto it = cachedClasses.find(className);
	if (it != cachedClasses.end())
		return it->second;

	return NULL;
}

ClassCacheList JVM::GetClassList()
{
	return cachedClasses;
}
