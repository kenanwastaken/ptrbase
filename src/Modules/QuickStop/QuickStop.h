#pragma once

namespace F::MOVEMENT::QUICKSTOP
{
	inline bool isEnabled = true;
	inline bool disableInAir = true;
	inline float factor = 100.0f;

	void onSetup();
	void onTick();
	void onRenderMenu();
}