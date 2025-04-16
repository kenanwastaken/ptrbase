#ifndef HOOK_H_
#define HOOK_H_

#include <Windows.h>

class MenuHook
{
	bool Init();
	void Shutdown();
	bool IsInit() { return isInitilaized; }

private:
	typedef BOOL(__stdcall* tWglSwapBuffer) (HDC hDc);
	static tWglSwapBuffer o_tWglSwapBuffer;

	static HWND WndHandle;
	static WNDPROC oWndProc;
	void* pSwapBuffers;

	bool isInitilaized;

	static LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static bool __stdcall wglSwapBuffers(HDC hDc);
};

#endif