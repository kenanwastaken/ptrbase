#pragma once
#include "../CEntity/CEntityPlayer/CEntityPlayer.h"
#include "../../Java/CList/CList.h"

class CWorld : public CObject
{
public:
	CWorld(CObject world) : CObject(world) {}

	CList GetPlayerEntities();

private:
	CClass m_Class = CClass("net.minecraft.world.World");
};