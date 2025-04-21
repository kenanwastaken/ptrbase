#include "CEntityLivingBase.h"
#include "../../../Java/CField/CField.h"

jboolean CEntityLivingBase::isJumping()
{
	return CField(GetObj(), m_Class.GetFieldID("isJumping", "Z")).GetBoolean();
}
