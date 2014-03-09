#pragma once
class GameMechanics
{
private:
	int currentNumber, yourWins, emilysWins;
	bool hardMode;
public:
	GameMechanics();
	~GameMechanics();
	int getCurrentNumber();
	int getYourWins();
	int getEmilysWins();
	int getTotalWins();
	bool isInHardMode();
	void resetCurrentNumber();
	void setHardMode(bool newSetting);
	int raiseCurrentNumber(int amount);
	int youWin(int amount);
	int emilyWins(int amount);
};

