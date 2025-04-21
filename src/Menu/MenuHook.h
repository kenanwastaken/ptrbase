#ifndef HOOK_H_
#define HOOK_H_

#include <Windows.h>
#include <gl/GL.h>

namespace MenuHook
{
	void Init();
	void Shutdown();

	bool getIsInit();
}

#endif