#pragma once
#include<chrono>

class Timer
{
public:
	Timer();
	double Mark();
	double Peek();
private:
	std::chrono::steady_clock::time_point last;
};