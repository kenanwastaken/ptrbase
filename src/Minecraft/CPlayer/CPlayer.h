#pragma once
#include "../CObject/CObject.h"
#include "../CClass/CClass.h"
#include "../Datatypes/Vec.h"

class CPlayer
{
public:
	CPlayer(CObject PlayerInstance) : m_PlayerInstance(PlayerInstance) {}

	CObject Instance() { return m_PlayerInstance; };

	//Location
	Vec3d GetPos();

	//Movement
	jboolean isSneaking();
private:
	CObject m_PlayerInstance;
	CClass	m_EntityClass = CClass("net.minecraft.entity.Entity");
};