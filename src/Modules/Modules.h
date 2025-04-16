#pragma once
#include <functional>

#include "FastPlace/FastPlace.h"

class Module;
inline std::vector<Module> g_Modules;

class Module
{
public:
	Module(std::function<void()> onSetup, std::function<void()> onTick, std::function<void()> renderMenu)
		: m_OnSetup(onSetup), m_OnTick(onTick), m_RenderMenu(renderMenu) 
	{
		g_Modules.emplace_back(*this);
	};

	std::function<void()> m_OnSetup;
	std::function<void()> m_OnTick;
	std::function<void()> m_RenderMenu;
};

namespace MODULES
{
	inline Module FastPlace(MODULES::FASTPLACE::onSetup, MODULES::FASTPLACE::onTick, MODULES::FASTPLACE::renderMenu);
}