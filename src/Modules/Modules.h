#include <functional>
#include <thread>
#include <iostream>
#include "../Helpers/Singleton.h"

#include "FastPlace/FastPlace.h"
#include "QuickStop/QuickStop.h"

class Module
{
public:
	Module(std::function<void()> onSetup, std::function<void()> onTick, std::function<void()> onMenu) : m_OnSetup(onSetup), m_OnTick(onTick), m_OnMenu(onMenu)
	{
		m_OnSetup();
	}

	void RenderMenu() { m_OnMenu(); }
	void Tick() { m_OnTick(); }

	bool isEnabled() { return m_Enabled; };
	void Toggle() { m_Enabled = !m_Enabled; }

private:
	std::thread m_Thread;
	std::function<void()> m_OnSetup;
	std::function<void()> m_OnTick;
	std::function<void()> m_OnMenu;

	bool m_Enabled = true;
};

class ModuleManager : public Singleton<ModuleManager>
{
public:
	void EnableModules()
	{
		m_Modules.emplace_back(std::make_unique<Module>(F::MISC::FASTPLACE::onSetup, F::MISC::FASTPLACE::onTick, F::MISC::FASTPLACE::onRenderMenu));
		m_Modules.emplace_back(std::make_unique<Module>(F::MOVEMENT::QUICKSTOP::onSetup, F::MOVEMENT::QUICKSTOP::onTick, F::MOVEMENT::QUICKSTOP::onRenderMenu));
		
		std::cout << m_Modules.size() << " Modules Enabled!\n";
	}

	void RenderMenu()
	{
		for (auto& m : m_Modules)
		{
			m->RenderMenu();
		}
	}

	void Tick()
	{
		for (auto& m : m_Modules)
		{
			m->Tick();
		}
	}

	std::vector<std::unique_ptr<Module>>& GetModules() { return m_Modules; }
protected:
	ModuleManager() { m_Modules.clear(); };

private:
	std::vector<std::unique_ptr<Module>> m_Modules;
};