#include "CCacheManager.h"

void CCacheManager::UpdateCache(CacheVar var)
{
	switch (var)
	{
	case CacheVar_All:
		m_Minecraft = CMinecraft::GetMinecraft();
		m_GameSettings = m_Minecraft.GetSettings();
	case CacheVar_Minecraft:
		m_Minecraft = CMinecraft::GetMinecraft();
	case CacheVar_GameSettings:
		m_GameSettings = m_Minecraft.GetSettings();
	}
}

CCacheManager::CCacheManager()
{
	m_Minecraft = CMinecraft::GetMinecraft();
	m_GameSettings = m_Minecraft.GetSettings();
}
