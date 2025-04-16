#include "CMinecraft.h"
#include "../JVM/JVM.h"

CMinecraft::CMinecraft()
{
	jfieldID field = g_JVM->m_Env->GetStaticFieldID(mcClass.Class(), "theMinecraft", "Lnet/minecraft/client/Minecraft;");
	this->mcObj = CObject(g_JVM->m_Env->GetStaticObjectField(mcClass.Class(), field));
}

CClass CMinecraft::GetClass()
{
	return this->mcClass;
}

CObject CMinecraft::GetMinecraft()
{
	return this->mcObj;
}

jboolean CMinecraft::IsInGame()
{
	return this->GetLocalPlayer().Instance().Obj() == NULL ? JNI_FALSE : JNI_TRUE;
}

CPlayer CMinecraft::GetLocalPlayer()
{
	jfieldID getPlayer = g_JVM->m_Env->GetFieldID(mcClass.Class(), "thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;");
	jobject localPlayer = g_JVM->m_Env->GetObjectField(mcObj.Obj(), getPlayer);

	return CPlayer(localPlayer);
}

jint CMinecraft::GetRightClickDelay()
{
	jfieldID rcd = g_JVM->m_Env->GetFieldID(mcClass.Class(), "rightClickDelayTimer", "I");
	return g_JVM->m_Env->GetIntField(mcObj.Obj(), rcd);
}

void CMinecraft::SetRightClickDelay(jint delay)
{
	jfieldID rcd = g_JVM->m_Env->GetFieldID(mcClass.Class(), "rightClickDelayTimer", "I");
	g_JVM->m_Env->SetIntField(mcObj.Obj(), rcd, delay);
}

CMovingObjectPosition CMinecraft::GetObjectMouseOver()
{
	return CMovingObjectPosition(g_JVM->m_Env->GetObjectField(mcObj.Obj(), g_JVM->m_Env->GetFieldID(mcClass.Class(), "objectMouseOver", "Lnet/minecraft/util/MovingObjectPosition;")));
}
