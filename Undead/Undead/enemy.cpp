#include "enemy.h"

using namespace std;
using namespace sf;

//========================================================================================================================
// Constructeurs
Enemy::Enemy()
{
	_color = sf::Color::Blue;
	_name = "Default";
	_maxHealth = 10;
	_health = 10;
	_damage = 5;
	_speed = 1;
	_xp = 1;
	_dmgEffectCooldown = 0;

	_direction = 0,
	_rotation = 0,
	_velocityX = 0,
	_velocityY = 0,
	_positionX = 0,
	_positionY = 0;
}

Enemy::~Enemy()
{
	_color = sf::Color::Black;
	_name = "";
	_maxHealth = 0;
	_health = 0;
	_damage = 0;
	_speed = 0;
	_xp = 0;
	_dmgEffectCooldown = 0;

	_direction = 0,
	_rotation = 0,
	_velocityX = 0,
	_velocityY = 0,
	_positionX = 0,
	_positionY = 0;
}

//========================================================================================================================
// Getters
sf::Color Enemy::mGetColor() const
{
	return _color;
}

std::string Enemy::mGetName() const
{
	return _name;
}

int Enemy::mGetMaxHealth() const
{
	return _maxHealth;
}

int Enemy::mGetHealth() const
{
	return _health;
}

int Enemy::mGetSpeed() const
{
	return _speed;
}

int Enemy::mGetDamage() const
{
	return _damage;
}

int Enemy::mGetXp() const
{
	return _xp;
}

int Enemy::mGetDmgEffectCooldown() const
{
	return _dmgEffectCooldown;
}

int Enemy::mGetDirection() const
{
	return _direction;
}

int Enemy::mGetRotation() const
{
	return _rotation;
}

int Enemy::mGetVelocityX() const
{
	return _velocityX;
}

int Enemy::mGetVelocityY() const
{
	return _velocityY;
}

int Enemy::mGetPositionX() const
{
	return _positionX;
}

int Enemy::mGetPositionY() const
{
	return _positionY;
}

//========================================================================================================================
// Setters
void Enemy::mSetColor(const sf::Color color)
{
	_color = color;
}

void Enemy::mSetName(const std::string name)
{
	_name = name;
}

void Enemy::mSetMaxHealth(const int maxHealth)
{
	_maxHealth = maxHealth;
}

void Enemy::mSetHealth(const int health)
{
	_health = health;
}

void Enemy::mSetSpeed(const int speed)
{
	_speed = speed;
}

void Enemy::mSetDamage(const int damage)
{
	_damage = damage;
}

void Enemy::mSetXp(const int xp)
{
	_xp = xp;
}

void Enemy::mSetDmgEffectCooldown(const int cooldown)
{
	_dmgEffectCooldown = cooldown;
}

void Enemy::mSetDirection(const int dir)
{
	assert(dir >= 0 && dir <= 4);
	_direction = dir;
}

void Enemy::mSetRotation(const int rot)
{
	_rotation = rot;
}

void Enemy::mSetVelocityX(const int x)
{
	_velocityX = x;
}

void Enemy::mSetVelocityY(const int y)
{
	_velocityY = y;
}

void Enemy::mSetPositionX(const int x)
{
	_positionX = x;
}

void Enemy::mSetPositionY(const int y)
{
	_positionY = y;
}

//========================================================================================================================
// Autres
void Enemy::mInitializeMovement(const int playerX, const int playerY)
{
	if (mGetPositionX() > playerX)
	{
		mSetVelocityX(-mGetSpeed());
	}
	else if (mGetPositionX() < playerX)
	{
		mSetVelocityX(mGetSpeed());
	}
	else
	{
		mSetVelocityX(0);
	}

	if (mGetPositionY() > playerY)
	{
		mSetVelocityY(-mGetSpeed());
	}
	else if (mGetPositionY() < playerY)
	{
		mSetVelocityY(mGetSpeed());
	}
	else 
	{
		mSetVelocityY(0);
	}
}

void Enemy::mDamageEffect(sf::RectangleShape& enemyShape)
{
	mSetDmgEffectCooldown(5);
	enemyShape.setFillColor(sf::Color::White);
}

void Enemy::mDamageEffectTick(sf::RectangleShape& enemyShape)
{
	if (mGetDmgEffectCooldown() > 0)
	{
		mSetDmgEffectCooldown(mGetDmgEffectCooldown() - 1);
		enemyShape.setFillColor(mGetColor());
	}
}

void Enemy::mSetEnemyType(int type, sf::RectangleShape& enemyShape)
{
	switch (type)
	{
	case 1: // Default, first enemy

		mSetName("Default");
		mSetMaxHealth(10);
		mSetHealth(mGetMaxHealth());
		mSetDamage(5);
		mSetSpeed(1);
		mSetXp(1);
		mSetColor(sf::Color::Blue);
		enemyShape.setFillColor(sf::Color::Blue);
		break;

	case 2: // Fast but low hp

		mSetName("Runner");
		mSetMaxHealth(5);
		mSetHealth(mGetMaxHealth());
		mSetDamage(5);
		mSetSpeed(2);
		mSetXp(1);
		mSetColor(sf::Color::Yellow);
		enemyShape.setFillColor(sf::Color::Yellow);
		break;

	case 3: // Slow but tanky

		mSetName("Tank");
		mSetMaxHealth(25);
		mSetHealth(mGetMaxHealth());
		mSetDamage(5);
		mSetSpeed(1);
		mSetXp(1);
		mSetColor(sf::Color::Green);
		enemyShape.setFillColor(sf::Color::Green);
		break;

	default: // Default enemy

		mSetName("Default");
		mSetMaxHealth(10);
		mSetHealth(mGetMaxHealth());
		mSetDamage(5);
		mSetSpeed(1);
		mSetXp(1);
		mSetColor(sf::Color::Blue);
		break;

	}
}
