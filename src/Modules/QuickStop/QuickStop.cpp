#include "QuickStop.h"
#include <imgui.h>
#include <cmath>
#include "../../Minecraft/CCacheManager/CCacheManager.h"
#include <Windows.h>
#include "../../Helpers/CTimer.h"

void F::MOVEMENT::QUICKSTOP::onSetup()
{

}

void F::MOVEMENT::QUICKSTOP::onTick()
{
    if (!isEnabled)
        return;

    if (!(GetAsyncKeyState('A') & 0x8000) 
        && !(GetAsyncKeyState('D') & 0x8000) 
        && !(GetAsyncKeyState('W') & 0x8000) 
        && !(GetAsyncKeyState('S') & 0x8000)
        && (disableInAir ? (CCacheManager::GetInstance().Minecraft().GetLocalPlayer().GetOnGround()) : true)
        )
    {
        auto player = CCacheManager::GetInstance().Minecraft().GetLocalPlayer();

        double motionX = player.GetMotion().GetX();
        double motionZ = player.GetMotion().GetY();

        float factorRatio = factor / 100.0f;
        motionX -= motionX * factorRatio;
        motionZ -= motionZ * factorRatio;

        if (fabs(motionX) < 0.01f) motionX = 0;
        if (fabs(motionZ) < 0.01f) motionZ = 0;

        player.SetMotionX(motionX);
        player.SetMotionZ(motionZ);
    }
}

void F::MOVEMENT::QUICKSTOP::onRenderMenu()
{
	ImGui::Checkbox("QuickStop", &isEnabled);
    if (isEnabled)
    {
        ImGui::SliderFloat("Factor", &factor, 0.0f, 100.0f);
        ImGui::Checkbox("Disable on air", &disableInAir);
    }
}