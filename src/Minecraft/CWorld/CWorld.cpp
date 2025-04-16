#include "CWorld.h"
#include "../JVM/JVM.h"
	
std::vector<CPlayer> CWorld::GetPlayerList()
{
	std::vector<CPlayer> players;

	jmethodID EntityFieldID = g_JVM->m_Env->GetMethodID(m_WorldClass.Class(), "getLoadedEntityList", "()Ljava/util/List;");

	return players;
}
