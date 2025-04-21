#ifndef HOOK_H_
#define HOOK_H_

#include <Windows.h>
#include <gl/GL.h>

namespace MenuHook
{
	inline bool doDraw = false;

	void Enable();
	void Disable();
}

#endif