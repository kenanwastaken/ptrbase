#ifndef _GUI_H_
#define _GUI_H_

#include <Windows.h>
#include <imgui.h>

namespace GUI
{
	inline bool doDraw = true;

	void Init(HWND wnd_handle);
	void Shutdown();
	void Render();
}

#endif