#pragma once
#include "AIPlayer.h"
class HardOpponent :
	public AIPlayer
{
public:
	HardOpponent();
	~HardOpponent();
	int decide(int currentNumber);
};

