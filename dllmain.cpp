#include <Windows.h>
#include <stdio.h>
#include <thread>

#include "src/Menu/MenuHook.h"
#include "src/Minecraft/CMinecraft/CMinecraft.h"
#include "src/Minecraft/CCacheManager/CCacheManager.h"
#include "src/Java/JVM/JVM.h"
#include "src/Modules/Modules.h"
#include <imgui.h>
#include <iostream>

void __stdcall MainThread(HINSTANCE hInstance)
{
    MenuHook::Enable();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    JVM::GetInstance();
    CMinecraft::GetMinecraft();
    ModuleManager::GetInstance().EnableModules();
    CCacheManager::GetInstance();

    while (!GetAsyncKeyState(VK_END))
    {
        //i wanted to make a like a thread to update it but idk why threads crashes it for now its like that my dawg! proble cause: "async"
        ModuleManager::GetInstance().Tick();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    for (auto& m : ModuleManager::GetInstance().GetModules())
    {
        if (m->isEnabled())
            m->Toggle();
    }

    MenuHook::Disable();

    FreeLibrary(hInstance);
}

BOOL APIENTRY DllMain( HINSTANCE hInstance,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hInstance);

        AllocConsole();
        SetConsoleTitleA("ptrhack Debug");
        freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

        std::cout << "       _        _                _    " << "\n";
        std::cout << " _ __ | |_ _ __| |__   __ _  ___| | __" << "\n";
        std::cout << "| '_ \\| __| '__| '_ \\ / _` |/ __| |/ /" << "\n";
        std::cout << "| |_) | |_| |  | | | | (_| | (__|   < " << "\n";
        std::cout << "| .__/ \\__|_|  |_| |_|\\__,_|\\___|_|\\_\\" << "\n";
        std::cout << "|_|                                   " << "\n";
        std::cout << "                        by kenanwastaken" << "\n";
        std::cout << "" << "\n";
        std::cout << "\"We paste shit, that doesnt prove we aint living for this shit.\"" << "\n";
        std::cout << "\"me dum this window will always be opened, me dum didnt setup debug conf.\"" << "\n";

        if (static std::thread main_thread([hInstance] { MainThread(hInstance); }); main_thread.joinable())
            main_thread.detach();
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
        FreeConsole();
        fclose(stdout);
    }
    return TRUE;
}

