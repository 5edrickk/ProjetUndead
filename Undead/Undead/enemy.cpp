#include "enemy.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Enemy::Enemy()
{
	_posX = 0;
	_posY = 0;
	_maxHealth = 100;
	_currentHealth = 100;
	_speed = 10;
	_direction = 0;
	_rotation = 90;
}

Enemy::~Enemy()
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
int Enemy::mGetPosX() const
{
	return _posX;
}

int Enemy::mGetPosY() const
{
	return _posY;
}

int Enemy::mGetDirection() const
{
	return _direction;
}

//========================================================================================================================
// Setters
void Enemy::mSetPosX(const int x)
{
	_posX = x;
}

void Enemy::mSetPosY(const int y)
{
	_posY = y;
}

void Enemy::mSetDirection(const int dir)
{
	assert(dir >= 0 && dir <= 4);
	_direction = dir;
}
