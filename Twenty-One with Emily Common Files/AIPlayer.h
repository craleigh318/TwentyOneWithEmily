#pragma once
#include "Player.h"
class AIPlayer :
	public Player
{
public:
	AIPlayer();
	~AIPlayer();
	virtual int decide(int currentNumber) = 0;
};

