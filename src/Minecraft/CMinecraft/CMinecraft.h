#pragma once
#include "../../Java/CObject/CObject.h"
#include "../../Java/CClass/CClass.h"
#include "../Settings/CGameSettings.h"
#include "../CEntity/CEntityPlayer/CEntityPlayer.h"
#include "../CWorld/CWorldClient/CWorldClient.h"

class CMinecraft : public CObject
{
public:
	CMinecraft(CObject minecraft_obj) : CObject(minecraft_obj) {}

	static CMinecraft	GetMinecraft();
	CWorldClient		GetWorld();
	CGameSettings		GetSettings();

	CEntityPlayer		GetLocalPlayer();

	jint GetRightClickTimer();
	void SetRightClickTimer(jint delay);
private:
	CClass m_Class = CClass("net.minecraft.client.Minecraft");
};