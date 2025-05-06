#pragma once

#include <cassert>
#include <string>
#include <iostream>

class Enemy {
private:
	std::string _name;
		int _maxHealth,
		_health,
		_speed,
		_damage,
		_xp,

		_direction,
		_rotation,
		_velocityX,
		_velocityY,
		_positionX,
		_positionY;

public:
	// Constructeurs
	Enemy();
	~Enemy();

	// Getters
	int mGetMaxHealth() const;
	int mGetHealth() const;
	int mGetSpeed() const;
	int mGetDamage() const;
	int mGetXp() const;

	int mGetDirection() const;
	int mGetRotation() const;
	int mGetVelocityX() const;
	int mGetVelocityY() const;
	int mGetPositionX() const;
	int mGetPositionY() const;

	// Setters
	void mSetMaxHealth(const int maxHealth);
	void mSetHealth(const int health);
	void mSetSpeed(const int speed);
	void mSetDamage(const int damage);
	void mSetXp(const int xp);

	void mSetDirection(const int dir);
	void mSetRotation(const int rot);
	void mSetVelocityX(const int x);
	void mSetVelocityY(const int y);
	void mSetPositionX(const int x);
	void mSetPositionY(const int y);

	// Autres
	void mInitializeMovement(const int playerX, const int playerY);

};