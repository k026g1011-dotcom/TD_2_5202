#pragma once
#include "CommandInput.h"
class Minigame
{
private:
	int bgGh_ = 0;
	CommandInput* commands_ = nullptr;
public:
	virtual void Start(CommandInput* input);
	virtual void Update() = 0;
	virtual void End() = 0;
	virtual void Draw();
	void SetBgGh(int bgGh);
	CommandInput* GetCommand();
};

