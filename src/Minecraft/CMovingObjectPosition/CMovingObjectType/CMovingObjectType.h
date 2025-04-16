#pragma once
#include "../../CClass/CClass.h"
#include "../../CObject/CObject.h"

class CMovingObjectType
{
public:
    CMovingObjectType(CObject object) : m_Object(object) {};

    static CMovingObjectType    GetType(const char* Name);
    CObject				        GetObj() { return m_Object; }
public:
    inline static CClass m_Class = CClass("net.minecraft.util.MovingObjectPosition$MovingObjectType");
    CObject m_Object;
};