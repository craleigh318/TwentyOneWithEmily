#include "stdafx.h"
#include "Emily.h"


Emily::Emily()
{
}


Emily::~Emily()
{
}

int Emily::decide(int currentNumber)
{
	int remainder;
	remainder = currentNumber % 3;
	if (remainder > 1)
	{
		//Add three.
		return 3;
	}
	else if (remainder < 1)
	{
		//Add two.
		return 2;
	}
	else
	{
		//Add one.
		return 1;
	}
}