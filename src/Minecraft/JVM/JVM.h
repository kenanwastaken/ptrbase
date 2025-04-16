#pragma once
#include <jni.h>
#include <jvmti.h>
#include <iostream>
#include <boost/container/flat_map.hpp>

typedef std::unordered_map<std::string, jclass> ClassCacheList;

class JVM
{
public:
	JVM();

	bool			Load();
	jclass			GetClass(std::string className);
	ClassCacheList	GetClassList();


	JavaVM*		m_Vm	= nullptr;
	JNIEnv*		m_Env	= nullptr;
	jvmtiEnv*	m_tiEnv	= nullptr;
private:
	ClassCacheList cachedClasses;
};

inline std::unique_ptr<JVM> g_JVM = std::make_unique<JVM>();