#pragma once
#include <bitset>
#include <optional>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool ReadKeyPressed(unsigned char keycode);
	void SetKeyPressState(unsigned char keycode);
private:
	static const unsigned int nKeys = 256u;
	std::bitset<nKeys> keystates;
};