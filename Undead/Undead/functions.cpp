#include "functions.h"

using namespace std;

void fDebug(int code, int param1, int param2) 
{
	if (DEBUG == true)
	{
		switch (code)
		{
		case 0:
			cout << "DEBUG : Unknown" << endl;
			break;
		case 1:
			cout << "DEBUG : Player hit window border" << endl;
			break;
		case 2:
			cout << "DEBUG : Player position : " << param1 << "x " << param2 << "y" << endl;
			break;
		case 3:
			cout << "DEBUG : Mouse Position : " << param1 << "x " << param2 << "y (" << fWindowClamp(param1, 'x') << "x " << fWindowClamp(param2, 'y') << "y)" << endl;
			break;
		case 4:
			cout << "DEBUG : Player rotation : " << param1 << endl;
			break;
		default:
			cout << "DEBUG : Default" << endl;
			break;
		}
	}
}

int fWindowClamp(int value, char direction)
{
	if (direction == 'x')
	{
		if (value < 0)
		{
			return 0;
		}
		else if (value > WINDOW_SIZE_X) 
		{
			return WINDOW_SIZE_X;
		}
	}
	else if (direction == 'y')
	{
		if (value < 0)
		{
			return 0;
		}
		else if (value > WINDOW_SIZE_Y)
		{
			return WINDOW_SIZE_Y;
		}
	}

	return value;
}

int fPlayerMove(int direction, sf::RectangleShape& player, int posX, int posY) 
{
	switch (direction) 
	{
	case 1: // Up
		if (posY > 0)
		{
			player.move(0, -INCREMENT);
			posY -= INCREMENT;
		}
		else { fDebug(1); }

		return posY;
	case 2: // Right
		if (posX < WINDOW_SIZE_X - PLAYER_SIZE)
		{
			player.move(INCREMENT, 0);
			posX += INCREMENT;
		}
		else { fDebug(1); }

		return posX;
	case 3: // Down
		if (posY < WINDOW_SIZE_Y - PLAYER_SIZE)
		{
			player.move(0, INCREMENT);
			posY += INCREMENT;
		}
		else { fDebug(1); }

		return posY;
	case 4: // Left
		if (posX > 0)
		{
			player.move(-INCREMENT, 0);
			posX -= INCREMENT;
		}
		else { fDebug(1); }

		return posX;
	default:
		return 0;
	}
}

void fInitialize() 
{

}