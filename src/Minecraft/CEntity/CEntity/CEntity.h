#pragma once
#include "../../../Java/CObject/CObject.h"
#include "../../../Java/CClass/CClass.h"
#include "../../../Helpers/Math/Math.h"


class CEntity : public CObject
{
public:
	CEntity(CObject obj) : CObject(obj) { }

	jboolean isDead();

	Math::Vec3d GetPosition();
	Math::Vec3d GetMotion();

	void	SetMotionX(jdouble val);
	void	SetMotionY(jdouble val);
	void	SetMotionZ(jdouble val);

	Math::VecRotation GetRotation();

	jboolean GetOnGround();
private:
	CClass m_Class = CClass("net.minecraft.entity.Entity");
};