#include "FastPlace.h"
#include <iostream>
#include <ImGui/imgui.h>
#include <Windows.h>
#include "../../Minecraft/Globals.h"

void MODULES::FASTPLACE::onSetup()
{
}

void MODULES::FASTPLACE::onTick()
{
	if (!enabled || !GetAsyncKeyState(VK_RBUTTON) || !GLOBALS::g_Minecraft->IsInGame()) return;

	GLOBALS::g_Minecraft->SetRightClickDelay(0);
}

void MODULES::FASTPLACE::renderMenu()
{
	ImGui::Checkbox("Fast Place", &enabled);
}

