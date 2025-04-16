#pragma once
#include "CMovingObjectType/CMovingObjectType.h"

class CMovingObjectPosition
{
public:
	CMovingObjectPosition(CObject object) : m_Object(object) {};

	CMovingObjectType	GetType();
	CObject				GetObj() { return m_Object; }
private:
	inline static CClass m_Class = CClass("net/minecraft/util/MovingObjectPosition");
	CObject m_Object;
};