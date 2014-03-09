// Back End.h

#pragma once

#include "Model.h"

using namespace System;

namespace BackEnd {

	public ref class ManagedModel
	{
	private:
		Model* model;
	protected:
		!ManagedModel();
	public:
		ManagedModel();
		~ManagedModel();
		int getCurrentNumber();
		int getYourWins();
		int getEmilysWins();
		int getTotalWins();
		bool isInHardMode();
		void startNewGame();
		void setHardMode(bool newSetting);
		int raiseCurrentNumber(int amount);
	};
}
