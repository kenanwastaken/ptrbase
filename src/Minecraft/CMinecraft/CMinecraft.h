#pragma once
#include "../CObject/CObject.h"
#include "../CClass/CClass.h"
#include "../CPlayer/CPlayer.h"
#include "../CMovingObjectPosition/CMovingObjectPosition.h"

class CMinecraft
{
public:
	CMinecraft();
	CMinecraft(CObject mc) : mcObj(mc) {};

	CClass						GetClass();
	CObject						GetMinecraft();
	
	jboolean					IsInGame();
	CPlayer						GetLocalPlayer();

	jint						GetRightClickDelay();
	void						SetRightClickDelay(jint delay);
	CMovingObjectPosition		GetObjectMouseOver();
private:
	CObject mcObj	= nullptr;
	CClass	mcClass = CClass("net.minecraft.client.Minecraft");
};