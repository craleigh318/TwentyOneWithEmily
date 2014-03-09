// This is the main DLL file.

#include "stdafx.h"

#include "Back End.h"

namespace BackEnd
{
	ManagedModel::ManagedModel() :model(new Model())
	{
	}

	ManagedModel::~ManagedModel()
	{
		this->!ManagedModel();
	}

	ManagedModel::!ManagedModel()
	{
		delete model;
	}

	int ManagedModel::getCurrentNumber()
	{
		return model->getCurrentNumber();
	}

	int ManagedModel::getYourWins()
	{
		return model->getYourWins();
	}

	int ManagedModel::getEmilysWins()
	{
		return model->getEmilysWins();
	}

	int ManagedModel::getTotalWins()
	{
		return model->getTotalWins();
	}

	bool ManagedModel::isInHardMode()
	{
		return model->isInHardMode();
	}

	void ManagedModel::startNewGame()
	{
		model->startNewGame();
	}

	void ManagedModel::setHardMode(bool newSetting)
	{
		model->setHardMode(newSetting);
	}

	int ManagedModel::raiseCurrentNumber(int amount)
	{
		return model->raiseCurrentNumber(amount);
	}
}