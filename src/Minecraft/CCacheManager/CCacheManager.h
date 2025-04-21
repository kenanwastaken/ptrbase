#pragma once
#include "../CMinecraft/CMinecraft.h"
#include "../../Helpers/Singleton.h"

typedef enum CacheVar_
{
	CacheVar_All,
	CacheVar_Minecraft,
	CacheVar_GameSettings
} CacheVar;

class CCacheManager : public Singleton<CCacheManager>
{
public:
	CMinecraft Minecraft() { return m_Minecraft; }
	CGameSettings GameSetings() { return m_GameSettings; }

	void	UpdateCache(CacheVar var);
protected:
	CCacheManager();

private:
	CMinecraft m_Minecraft = CMinecraft(jobject(NULL));
	CGameSettings m_GameSettings = CGameSettings(jobject(NULL));
};