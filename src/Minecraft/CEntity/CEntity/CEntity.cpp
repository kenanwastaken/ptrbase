#include "CEntity.h"
#include "../../../Java/CField/CField.h"

jboolean CEntity::isDead()
{
	return CField(GetObj(), m_Class.GetFieldID("isDead", "Z")).GetBoolean();
}

Math::Vec3d CEntity::GetPosition()
{
	return Math::Vec3d(
		CField(GetObj(), m_Class.GetFieldID("posX", "D")).GetDouble(),
		CField(GetObj(), m_Class.GetFieldID("posY", "D")).GetDouble(),
		CField(GetObj(), m_Class.GetFieldID("posZ", "D")).GetDouble()
	);
}

Math::Vec3d CEntity::GetMotion()
{
	return Math::Vec3d(
		CField(GetObj(), m_Class.GetFieldID("motionX", "D")).GetDouble(), 
		CField(GetObj(), m_Class.GetFieldID("motionY", "D")).GetDouble(),
		CField(GetObj(), m_Class.GetFieldID("motionZ", "D")).GetDouble()
	);
}

void CEntity::SetMotionX(jdouble val)
{
	CField(GetObj(), m_Class.GetFieldID("motionX", "D")).SetDouble(val);
}

void CEntity::SetMotionY(jdouble val)
{
	CField(GetObj(), m_Class.GetFieldID("motionY", "D")).SetDouble(val);
}

void CEntity::SetMotionZ(jdouble val)
{
	CField(GetObj(), m_Class.GetFieldID("motionZ", "D")).SetDouble(val);
}

Math::VecRotation CEntity::GetRotation()
{
	return Math::VecRotation(
		CField(GetObj(), m_Class.GetFieldID("rotationYaw", "F")).GetFloat(), 
		CField(GetObj(), m_Class.GetFieldID("rotationPitch", "F")).GetFloat());
}

jboolean CEntity::GetOnGround()
{
	return CField(GetObj(), m_Class.GetFieldID("onGround", "Z")).GetBoolean();
}
