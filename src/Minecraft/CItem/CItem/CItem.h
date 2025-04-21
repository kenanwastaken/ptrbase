#pragma once
#include "../../../Java/CObject/CObject.h"
#include "../../../java/CClass/CClass.h"

class CItem : public CObject
{
public:
	CItem(CObject item) : CObject(item) {}

	const char* GetName(); 

private:
	CClass m_Class = CClass("net.minecraft.item.Item");
};