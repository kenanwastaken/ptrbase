#include "CMovingObjectType.h"
#include <string>
#include "../../JVM/JVM.h"

CMovingObjectType CMovingObjectType::GetType(const char* Name)
{
	return CMovingObjectType(g_JVM->m_Env->GetStaticObjectField(m_Class.Class(), g_JVM->m_Env->GetFieldID(m_Class.Class(), Name, "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;")));
}
