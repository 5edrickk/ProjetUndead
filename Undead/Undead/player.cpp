#include "player.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Player::Player()
{
	_posX = WINDOW_SIZE_X / 2 - PLAYER_SIZE / 2;
	_posY = WINDOW_SIZE_Y / 2 - PLAYER_SIZE / 2;
	_maxHealth = PLAYER_MAX_HEALTH;
	_currentHealth = PLAYER_MAX_HEALTH;
	_speed = PLAYER_SPEED;
	_direction = 0;
	_rotation = 90;
}

Player::~Player()
{
	_posX = 0;
	_posY = 0;
	_maxHealth = 0;
	_currentHealth = 0;
	_speed = 0;
	_direction = 0;
	_rotation = 0;
}

//========================================================================================================================
// Getters
int Player::mGetPosX() const
{
	return _posX;
}

int Player::mGetPosY() const
{
	return _posY;
}

int Player::mGetDirection() const
{
	return _direction;
}

//========================================================================================================================
// Setters
void Player::mSetPosX(const int x)
{
	_posX = x;
}

void Player::mSetPosY(const int y)
{
	_posY = y;
}

void Player::mSetDirection(const int dir)
{
	assert(dir >= 0 && dir <= 4);
	_direction = dir;
}
