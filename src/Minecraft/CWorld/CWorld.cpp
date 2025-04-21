#include "CWorld.h"
#include "../../Java/CField/CField.h"

CList CWorld::GetPlayerEntities()
{
	if (!isValid())
		return CList(NULL);

	return CList(CField(GetObj(), m_Class.GetFieldID("playerEntities", "Ljava/util/List;")).GetObject());
}
