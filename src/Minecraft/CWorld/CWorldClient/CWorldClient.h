#pragma once
#include "../../../Java/CObject/CObject.h"
#include "../../CEntity/CEntity/CEntity.h"
#include "../CWorld.h"

class CWorldClient : public CWorld
{
public:
	CWorldClient(CWorld worldobj) : CWorld(worldobj) {}
private:
	CClass m_Class = CClass("net.minecraft.client.multiplayer.WorldClient");
};