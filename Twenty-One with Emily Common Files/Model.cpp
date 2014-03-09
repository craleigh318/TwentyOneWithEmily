#include "stdafx.h"
#include "Model.h"
#include <random>
#include "HumanPlayer.h"
#include "Emily.h"
#include "HardOpponent.h"
#include "AIPlayer.h"


Model::Model()
{
	mechanics = new GameMechanics();
	opponent = new Emily();
}


Model::~Model()
{
	delete mechanics;
	delete opponent;
}

int Model::getCurrentNumber()
{
	return mechanics->getCurrentNumber();
}

int Model::getYourWins()
{
	return mechanics->getYourWins();
}

int Model::getEmilysWins()
{
	return mechanics->getEmilysWins();
}

int Model::getTotalWins()
{
	return mechanics->getTotalWins();
}

bool Model::isInHardMode()
{
	return mechanics->isInHardMode();
}

void Model::startNewGame()
{
	mechanics->resetCurrentNumber();
}

void Model::setHardMode(bool newSetting)
{
	delete opponent;
	if (newSetting)
	{
		opponent = new HardOpponent();
	}
	else
	{
		opponent = new Emily();
	}
	mechanics->setHardMode(newSetting);
	startNewGame();
}

int Model::decide()
{
	int decision = opponent->decide(mechanics->getCurrentNumber());
	return mechanics->raiseCurrentNumber(decision);
}

int Model::raiseCurrentNumber(int amount)
{
	int ret;
	if ((amount >= 1) && (amount <= 3))
	{
		int currentNumber = mechanics->raiseCurrentNumber(amount);
		if (currentNumber >= 21)
		{
			//Player loses.
			emilyWins(1);
			startNewGame();
			ret = -2;
		}
		else
		{
			currentNumber = decide();
			if (currentNumber >= 21)
			{
				//Opponent loses.
				youWin(1);
				startNewGame();
				ret = -3;
			}
			else
			{
				ret = currentNumber;
			}
		}
	}
	else
	{
		//Invalid amount.
		ret = -1;
	}
	return ret;
}

int Model::youWin(int amount)
{
	return mechanics->youWin(amount);
}

int Model::emilyWins(int amount)
{
	return mechanics->emilyWins(amount);
}