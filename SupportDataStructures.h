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
	double r;
	double g;
	double b;
	double a;
};