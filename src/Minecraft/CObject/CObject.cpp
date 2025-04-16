#include "CObject.h"
#include "../JVM/JVM.h"

CObject::~CObject()
{

}

jobject CObject::Obj()
{
	return m_Object;
}

