#include "Timer.h"

Timer::Timer()
{
	last = std::chrono::steady_clock::now();
}

double Timer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<double> frameTime = last - old;

	return frameTime.count();
}

double Timer::Peek()
{
	return std::chrono::duration<double>(std::chrono::steady_clock::now() - last).count();
}