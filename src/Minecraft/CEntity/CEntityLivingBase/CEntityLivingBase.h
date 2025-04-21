#pragma once
#include <jni/jni.h>
#include "../CEntity/CEntity.h"

class CEntityLivingBase : public CEntity
{
public:
	CEntityLivingBase(CEntity entity) : CEntity(entity) {};

	jboolean isJumping();
private:
	CClass m_Class = CClass("net.minecraft.entity.EntityLivingBase");
};