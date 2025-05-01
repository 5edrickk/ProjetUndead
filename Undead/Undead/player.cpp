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

int Player::mGetRotation() const
{
	return _rotation;
}

Abilities Player::mGetAbility(int slot) const
{
	return  _playerAbilities[slot];
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

void Player::mSetRotation(const int rot)
{
	_rotation = rot;
}

//========================================================================================================================
// Abilities
void Player::mSetActive(const int number, const bool active)
{
	_playerAbilities[number].mSetActive(active);
}

//========================================================================================================================
// Autres
void Player::mInitialize()
{
	_playerAbilities[0].mSetActive(true);
}

void Player::mRotate(int targetX, int targetY, Player& object)
{
	int amount = (180/ 3.141592653589793) * (atan2(targetX - object.mGetPosX() - PLAYER_SIZE / 2, targetY - object.mGetPosY() - PLAYER_SIZE / 2)) - 90;
	
	if (amount < 0)
	{
		amount += 360;
	}
	
	fDebug(4, amount);
	
	object.mSetRotation(amount);
}

bool Player::mCheckAttack(int slot)
{
	if (_playerAbilities[slot].mGetActive() == true && _playerAbilities[slot].mGetCooldown() == 0)
	{
		return true;
	}
}

void Player::mAttacked(int slot)
{
	_playerAbilities[slot].mSetCooldown(_playerAbilities[slot].mGetMaxCooldown());
}

void Player::mDecreaseCooldown(int slot)
{
	if (_playerAbilities[slot].mGetCooldown() > 0)
	{
		_playerAbilities[slot].mSetCooldown(_playerAbilities[slot].mGetCooldown() - 1);
	}
}
