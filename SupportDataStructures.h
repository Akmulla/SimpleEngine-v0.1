#pragma once

struct InputData
{
public:
	float verticalAxis;
	float horizontalAxis;

	void Clear()
	{
		verticalAxis = 0.0f;
		horizontalAxis = 0.0f;
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

struct Vertex
{
	float x;
	float y;
	float z;
};