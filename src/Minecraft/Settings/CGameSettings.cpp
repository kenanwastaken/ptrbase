#include "CGameSettings.h"
#include "../../Java/CField/CField.h"

jfloat CGameSettings::GetGamma()
{
	return CField(m_SettingObject, m_Class.GetFieldID("gammaSetting", "F")).GetFloat();
}

void CGameSettings::SetGamma(jfloat gamma)
{
	CField(m_SettingObject, m_Class.GetFieldID("gammaSetting", "F")).SetFloat(gamma);
}
