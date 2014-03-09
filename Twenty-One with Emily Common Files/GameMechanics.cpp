#include "stdafx.h"
#include "GameMechanics.h"


GameMechanics::GameMechanics()
{
	yourWins = 0;
	emilysWins = 0;
	hardMode = false;
	resetCurrentNumber();
}


GameMechanics::~GameMechanics()
{
}

int GameMechanics::getCurrentNumber()
{
	return currentNumber;
}

int GameMechanics::getYourWins()
{
	return yourWins;
}

int GameMechanics::getEmilysWins()
{
	return emilysWins;
}

int GameMechanics::getTotalWins()
{
	return (yourWins + emilysWins);
}

bool GameMechanics::isInHardMode()
{
	return hardMode;
}

void GameMechanics::resetCurrentNumber()
{
	currentNumber = 0;
}

void GameMechanics::setHardMode(bool newSetting)
{
	hardMode = newSetting;
}

int GameMechanics::raiseCurrentNumber(int amount)
{
	currentNumber += amount;
	return currentNumber;
}

int GameMechanics::youWin(int amount)
{
	yourWins += amount;
	return yourWins;
}

int GameMechanics::emilyWins(int amount)
{
	emilysWins += amount;
	return emilysWins;
}