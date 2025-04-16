/*
* This code mostly pasted from https://github.com/axxo1337/OpenGL-Hk by axxo1337
* Huge thanks to him ❤️
*/

#include <MinHook.h>
#include <gl/GL.h>
#include "MenuHook.h"
#include "GUI.h"

bool MenuHook::Init()
{
	if (isInitilaized)
		return;

	WndHandle = FindWindowA("LWJGL", nullptr);
	oWndProc = (WNDPROC)SetWindowLongPtrW(WndHandle, GWLP_WNDPROC, (LONG_PTR)WndProc);

	MH_Initialize();

	pSwapBuffers = (void*)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers");

	if (pSwapBuffers == nullptr)
	{
		printf("[-] Failed to get wglSwapBuffers' address\n");
		return true;
	}

	MH_CreateHook(pSwapBuffers, &wglSwapBuffers, (LPVOID*)&o_tWglSwapBuffer);

	MH_EnableHook(MH_ALL_HOOKS);

	isInitilaized = true;

	return false;
}

void MenuHook::Shutdown()
{
	if (!isInitilaized)
		return;

	SetWindowLongPtrW(WndHandle, GWLP_WNDPROC, (LONG_PTR)oWndProc);
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);

	isInitilaized = false;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall MenuHook::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (GUI::getIsInit())
	{
		if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			return true;
	}

	return CallWindowProcA(oWndProc, hWnd, msg, wParam, lParam);
}

bool __stdcall MenuHook::wglSwapBuffers(HDC hDc)
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

		GUI::init(WndHandle);

		was_init = true;
	}
	else
	{
		wglMakeCurrent(hDc, new_context);
		GUI::Render();
	}

	wglMakeCurrent(hDc, origin_context);

	return o_tWglSwapBuffer(hDc);
}
