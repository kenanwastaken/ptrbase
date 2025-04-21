#pragma once
#include "../../Java/CObject/CObject.h"
#include "../../Java/CClass/CClass.h"

class CGameSettings
{
public:
	CGameSettings(CObject setting_object) : m_SettingObject(setting_object) {}

	jfloat	GetGamma();
	void	SetGamma(jfloat gamma);

private:
	CClass m_Class = CClass("net.minecraft.client.settings.GameSettings");
	CObject m_SettingObject;
};