#pragma once
#include "../../Helpers/Singleton.h"
#include <jni/jni.h>
#include <jni/jvmti.h>
#include <unordered_map>
#include <string>
#include "../CClass/CClass.h"

typedef std::unordered_map<std::string, CClass> ClassCacheList;

class JVM : public Singleton<JVM>
{
public:
	JavaVM* m_Vm = nullptr;
	JNIEnv* m_Env = nullptr;
	jvmtiEnv* m_tiEnv = nullptr;
	
	CClass FindClass(const char* className);

protected:
	JVM();

private:
	ClassCacheList cachedClasses;
};