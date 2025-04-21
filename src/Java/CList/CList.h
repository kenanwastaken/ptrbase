#pragma once
#include "../CObject/CObject.h"
#include "../CMethod/CMethod.h"
#include "../JVM/JVM.h"
#include "../CClass/CClass.h"
#include <vector>

class CList : public CObject
{
public:
	CList(CObject listobj) : CObject(listobj) {}

	jint GetSize()
	{
		return CMethod(GetObj(), m_Class.GetMethodID("size", "()I")).GetInt();
	}

	template<typename T>
	std::vector<T> Get()
	{
		std::vector<T> list;

		if (!isValid())
			return list;

		auto sizeMethod = CMethod(GetObj(), m_Class.GetMethodID("size", "()I"));
		jmethodID getMethod = JVM::GetInstance().m_Env->GetMethodID(m_Class.GetClass(), "get", "(I)Ljava/lang/Object;");

		for (jint i = 0; i < sizeMethod.GetInt(); i++) {
			jobject element = JVM::GetInstance().m_Env->CallObjectMethod(GetObj(), getMethod, i);
			list.push_back(element);
		}

		return list;
	}
private:
	CClass m_Class = CClass("java.util.List");
};