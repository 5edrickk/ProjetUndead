#pragma once

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

#include "constantes.h"
#include "functions.h"
#include "abilities.h"

class Player {
private:
	int _posX,
		_posY,
		_maxHealth,
		_health,
		_speed,
		_direction,
		_rotation;

	Abilities _playerAbilities[PLAYER_ABILITY_SLOTS];

public:
	// Constructeurs
	Player();
	~Player();

	// Getters
	int mGetPosX() const;
	int mGetPosY() const;
	int mGetHealth() const;
	int mGetDirection() const;
	int mGetRotation() const;
	Abilities mGetAbility(int slot) const;

	// Setters
	void mSetPosX(const int x);
	void mSetPosY(const int y);
	void mSetHealth(const int health);
	void mSetDirection(const int dir);
	void mSetRotation(const int rot);

	// Abilities
	void mSetActive(const int number, const bool active);

	//Autres
	void mInitialize();
	void mRotate(int targetX, int targetY, Player& object);
	bool mCheckAttack(int slot);
	void mAttacked(int slot);
	void mDecreaseCooldown(int slot);
	void mUpdateAbility(int ID, int slot, int level);

	int mCheckAbilityID(const int slot);
	int mCheckAbilityLevel(const int slot);

};