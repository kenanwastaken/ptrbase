#include "CItemStack.h"
#include "../../../Java/CMethod/CMethod.h"
#include <iostream>

CItem CItemStack::GetItem()
{
	if (!isValid())
		return CItem(NULL);

	return CItem(CMethod(GetObj(), m_Class.GetMethodID("getItem", "()Lnet/minecraft/item/Item;")).GetObj());
}
