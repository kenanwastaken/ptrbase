#pragma once
#include <chrono>

class CTimer
{
public:
	CTimer(int xMs) : m_xMs(std::chrono::milliseconds(xMs)) {}

	bool isElapsed() 
	{
		std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - m_TimerBegin) >= m_xMs)
		{
			m_TimerBegin = currentTime;
			return true;
		}
		return false;
	};
private:
	std::chrono::steady_clock::time_point m_TimerBegin = std::chrono::steady_clock::now();
	std::chrono::milliseconds m_xMs;
};