#pragma once

struct InputData
{
public:
	double verticalAxis;
	double horizontalAxis;
	void Clear()
	{
		verticalAxis = 0.0;
		horizontalAxis = 0.0;
	}
};

struct ColorRGBA
{
public:
	float r;
	float g;
	float b;
	float a;
};