/*
* This code mostly taken from https://github.com/axxo1337/OpenGL-Hk so special thanks to axxo and his fingers:3

MIT License

Copyright (c) 2022 aXXo-dev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <MinHook.h>
#include "MenuHook.h"
#include "GUI.h"
#include <tuple>
#include <chrono>

typedef BOOL(__stdcall* TWglSwapBuffers) (HDC hDc);

bool isEnabled = false;
HWND WndHandle;
WNDPROC oWndProc{};
void* pSwapBuffers{};
TWglSwapBuffers oWglSwapBuffers{};

static LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static bool __stdcall hkWglSwapBuffers(HDC hDc);

void MenuHook::Enable()
{
	WndHandle = FindWindowA("LWJGL", nullptr);
	oWndProc = (WNDPROC)SetWindowLongPtrW(WndHandle, GWLP_WNDPROC, (LONG_PTR)WndProc);

	MH_Initialize();

	pSwapBuffers = (void*)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers");

	MH_CreateHook(pSwapBuffers, &hkWglSwapBuffers, (LPVOID*)&oWglSwapBuffers);
	MH_EnableHook(MH_ALL_HOOKS);

	return;
}

void MenuHook::Disable()
{
	SetWindowLongPtrW(WndHandle, GWLP_WNDPROC, (LONG_PTR)oWndProc);
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_KEYDOWN && wParam == VK_INSERT)
		MenuHook::doDraw = !MenuHook::doDraw;

	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam);
}

bool __stdcall hkWglSwapBuffers(HDC hDc)
{
	HGLRC oContext = wglGetCurrentContext();
	static HGLRC nContext;

	if (static bool was_init = false; was_init == false)
	{
		nContext = wglCreateContext(hDc);
		wglMakeCurrent(hDc, nContext);

		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		glViewport(0, 0, viewport[2], viewport[3]);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glDisable(GL_DEPTH_TEST);

		GUI::Init(WndHandle);

		was_init = true;
	}
	else
	{
		wglMakeCurrent(hDc, nContext);
		GUI::Render();
	}
	
	wglMakeCurrent(hDc, oContext);
	return oWglSwapBuffers(hDc);
}
