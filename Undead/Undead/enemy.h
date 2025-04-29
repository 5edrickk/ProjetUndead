#pragma once

#include <cassert>

class Enemy {
private:
	int _posX,
		_posY,
		_maxHealth,
		_currentHealth,
		_speed,
		_direction,
		_rotation;

public:
	// Constructeurs
	Enemy();
	~Enemy();

	// Getters
	int mGetPosX() const;
	int mGetPosY() const;
	int mGetDirection() const;

	// Setters
	void mSetPosX(const int x);
	void mSetPosY(const int y);
	void mSetDirection(const int dir);
};