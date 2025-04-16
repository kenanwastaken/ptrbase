#include "CMovingObjectPosition.h"
#include "../JVM/JVM.h"

CMovingObjectType CMovingObjectPosition::GetType()
{
	return CMovingObjectType(g_JVM->m_Env->GetObjectField(m_Object.Obj(), g_JVM->m_Env->GetFieldID(m_Class.Class(), "typeOfHit", "Lnet/minecraft/util/MovingObjectPosition$MovingObjectType;")));
}
