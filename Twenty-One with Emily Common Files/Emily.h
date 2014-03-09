#pragma once
#include "AIPlayer.h"
class Emily :
	public AIPlayer
{
public:
	Emily();
	~Emily();
	int decide(int currentNumber);
};

