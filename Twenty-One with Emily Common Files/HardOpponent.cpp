#include "stdafx.h"
#include "HardOpponent.h"


HardOpponent::HardOpponent()
{
}


HardOpponent::~HardOpponent()
{
}

int HardOpponent::decide(int currentNumber)
{
	int remainder;
	//Try to count to multiple of 4.
	remainder = currentNumber % 4;
	return 4 - remainder;
	if (remainder == 1)
	{
		//Add three.
		return 3;
	}
	else if (remainder == 3)
	{
		//Add one.
		return 1;
	}
	else
	{
		//Add two.
		return 2;
	}
}