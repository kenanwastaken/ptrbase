#pragma once

#include "../CObject/CObject.h"
#include "../CClass/CClass.h"
#include "../CPlayer/CPlayer.h"
#include <vector>

class CWorld
{
public:
	CWorld(CObject world) : m_World(world) {}

	CObject Instance() { return m_World; };

	std::vector<CPlayer> GetPlayerList();
private:
	CObject m_World;
	CClass	m_WorldClass = CClass("net.minecraft.world.World");
};
