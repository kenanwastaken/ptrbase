#ifndef GUI_H_
#define GUI_H_

#include <cstdio>

#include <Windows.h>
#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_win32.h>
#include <ImGui/imgui_impl_opengl3.h>

namespace GUI
{
	bool init(HWND wnd_handle);
	void shutdown();

	void Render();

	bool getIsInit();
}

#endif