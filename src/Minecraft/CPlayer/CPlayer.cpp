#include "CPlayer.h"
#include "../JVM/JVM.h"
#include "../Globals.h"

Vec3d CPlayer::GetPos()
{
	if (!GLOBALS::g_Minecraft->IsInGame())
		return Vec3d(0, 0, 0);

	jfieldID xField = g_JVM->m_Env->GetFieldID(m_EntityClass.Class(), "posX", "D");
	jdouble x = g_JVM->m_Env->GetDoubleField(m_PlayerInstance.Obj(), xField);

	jfieldID yField = g_JVM->m_Env->GetFieldID(m_EntityClass.Class(), "posY", "D");
	jdouble y = g_JVM->m_Env->GetDoubleField(m_PlayerInstance.Obj(), yField);

	jfieldID zField = g_JVM->m_Env->GetFieldID(m_EntityClass.Class(), "posZ", "D");
	jdouble z = g_JVM->m_Env->GetDoubleField(m_PlayerInstance.Obj(), zField);

	return Vec3d(x, y, z);
}

jboolean CPlayer::isSneaking()
{
	jmethodID isSneaking = g_JVM->m_Env->GetMethodID(m_EntityClass.Class(), "isSneaking", "()Z");
	return g_JVM->m_Env->CallBooleanMethod(m_PlayerInstance.Obj(), isSneaking);
}
