#include "CMinecraft.h"
#include "../../Java/CField/CField.h"
#include "../../Java/JVM/JVM.h"
#include <iostream>

CMinecraft CMinecraft::GetMinecraft()
{
	CClass m_Class = CClass("net.minecraft.client.Minecraft");
	return CMinecraft(CField(m_Class, m_Class.GetStaticFieldID("theMinecraft", "Lnet/minecraft/client/Minecraft;")).GetStaticObject());
}

CWorldClient CMinecraft::GetWorld()
{
	return CWorldClient(CField(GetObj(), m_Class.GetFieldID("theWorld", "Lnet/minecraft/client/multiplayer/WorldClient;")).GetObject());
}

CGameSettings CMinecraft::GetSettings()
{
	return CGameSettings(CField(GetObj(), m_Class.GetFieldID("gameSettings", "Lnet/minecraft/client/settings/GameSettings;")).GetObject());
}

CEntityPlayer CMinecraft::GetLocalPlayer()
{
	return CEntityLivingBase(CField(GetObj(), m_Class.GetFieldID("thePlayer", "Lnet/minecraft/client/entity/EntityPlayerSP;")).GetObject());
}

jint CMinecraft::GetRightClickTimer()
{
	return CField(GetObj(), m_Class.GetFieldID("rightClickDelayTimer", "I")).GetInt();
}

void CMinecraft::SetRightClickTimer(jint delay)
{
	CField(GetObj(), m_Class.GetFieldID("rightClickDelayTimer", "I")).SetInt(delay);
}
