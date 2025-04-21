#pragma once
#include "../CEntityLivingBase/CEntityLivingBase.h"
#include "../../CItem/CItemStack/CItemStack.h"

class CEntityPlayer : public CEntityLivingBase
{
public:
	CEntityPlayer(jobject obj) : CEntityLivingBase(CEntity(obj)) {}
	CEntityPlayer(CEntityLivingBase entitylivingbase) : CEntityLivingBase(entitylivingbase) {}

	CItemStack GetItemStackInUse();
	CItemStack GetHeldItem();

	const char* GetName();
private:
	CClass m_Class = CClass("net.minecraft.entity.player.EntityPlayer");
};