#pragma once
#include <memory>
#include "CMinecraft/CMinecraft.h"

namespace GLOBALS
{
	inline std::unique_ptr<CMinecraft> g_Minecraft;

	void Load();
}