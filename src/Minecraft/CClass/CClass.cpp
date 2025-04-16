#include "CClass.h"
#include "../JVM/JVM.h"

CClass::CClass(const char* name)
{
	cachedClass = g_JVM->GetClass(name);
}

CClass::~CClass()
{

}

jclass CClass::Class()
{
	return cachedClass;
}
