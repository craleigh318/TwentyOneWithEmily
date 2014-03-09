#pragma once

#include "GameMechanics.h"
#include "Player.h"
#include "AIPlayer.h"

class Model
{
private:
	GameMechanics* mechanics;
	AIPlayer* opponent;
	int decide();
	int youWin(int amount);
	int emilyWins(int amount);
public:
	Model();
	~Model();
	int getCurrentNumber();
	int getYourWins();
	int getEmilysWins();
	int getTotalWins();
	bool isInHardMode();
	void startNewGame();
	void setHardMode(bool newSetting);
	int raiseCurrentNumber(int amount);
};

