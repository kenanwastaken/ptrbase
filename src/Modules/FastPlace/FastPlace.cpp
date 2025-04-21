#include "FastPlace.h"
#include <imgui.h>
#include <iostream>
#include "../../Minecraft/CCacheManager/CCacheManager.h"

void F::MISC::FASTPLACE::onSetup()
{

}

void F::MISC::FASTPLACE::onTick()
{
	static CTimer ctimer(25);

	if (!isEnabled && !ctimer.isElapsed())
		return;

	CCacheManager::GetInstance().Minecraft().SetRightClickTimer(0);
}

void F::MISC::FASTPLACE::onRenderMenu()
{
	ImGui::Checkbox("FastPlace", &isEnabled);
}
