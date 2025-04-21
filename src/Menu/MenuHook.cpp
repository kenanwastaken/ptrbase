/*
* This code taken from https://github.com/axxo1337/OpenGL-Hk so special thanks to axxo and his fingers:3

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
#include <gl/GL.h>

#include "MenuHook.h"
#include "GUI.h"

typedef BOOL(__stdcall* TWglSwapBuffers) (HDC hDc);

static bool is_init{};
static HWND wnd_handle{};
static WNDPROC origin_wndproc{};
void* p_swap_buffers{};
TWglSwapBuffers origin_wglSwapBuffers{};

static LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static bool __stdcall wglSwapBuffers(HDC hDc);

//
// Management functions
//

void MenuHook::Init()
{
	if (is_init)
		return;

	wnd_handle = FindWindowA("LWJGL", nullptr);
	origin_wndproc = (WNDPROC)SetWindowLongPtrW(wnd_handle, GWLP_WNDPROC, (LONG_PTR)WndProc);

	MH_Initialize();
	p_swap_buffers = (void*)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers");

	MH_CreateHook(p_swap_buffers, &wglSwapBuffers, (LPVOID*)&origin_wglSwapBuffers);
	MH_EnableHook(MH_ALL_HOOKS);

	is_init = true;
}

void MenuHook::Shutdown()
{
	if (!is_init)
		return;

	SetWindowLongPtrW(wnd_handle, GWLP_WNDPROC, (LONG_PTR)origin_wndproc);
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);

	is_init = false;
}

bool MenuHook::getIsInit()
{
	return is_init;
}


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_KEYDOWN && wParam == VK_INSERT)
		GUI::doDraw = !GUI::doDraw;

	if (GUI::doDraw && ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return CallWindowProcA(origin_wndproc, hWnd, msg, wParam, lParam);
}

bool __stdcall wglSwapBuffers(HDC hDc)
{
	HGLRC origin_context{ wglGetCurrentContext() };
	static HGLRC new_context{};

	if (static bool was_init{}; was_init == false)
	{
		new_context = wglCreateContext(hDc);
		wglMakeCurrent(hDc, new_context);

		GLint viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		glViewport(0, 0, viewport[2], viewport[3]);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, viewport[2], viewport[3], 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glDisable(GL_DEPTH_TEST);

		GUI::Init(wnd_handle);

		was_init = true;
	}
	else
	{
		wglMakeCurrent(hDc, new_context);
		GUI::Render();
	}

	wglMakeCurrent(hDc, origin_context);

	return origin_wglSwapBuffers(hDc);
}