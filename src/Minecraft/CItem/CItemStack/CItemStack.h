#pragma once
#include "../../../Java/CObject/CObject.h"
#include "../CItem/CItem.h"

class CItemStack : public CObject
{
public:
	CItemStack(CObject itemstack) : CObject(itemstack) {}

	CItem GetItem();

private:
	CClass m_Class = CClass("net.minecraft.item.ItemStack");
};