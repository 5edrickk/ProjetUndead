#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "constantes.h"
#include "functions.h"
#include "abilities.h"

class Projectile {
private:
	std::string _name;
	int _damage,
		_lifetime,
		_speed,
		_size,
		_pierceAmount,
		_bounceAmount,
		_criticalMultiplier,
		_criticalChance,
		
		_rotation,
		_velocityX,
		_velocityY,
		_positionX,
		_positionY;

public:
	// Constructeurs
	Projectile();
	Projectile(std::string nam, int damage, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance);
	~Projectile();

	// Getters
	std::string mGetName() const;
	int mGetDamage() const;
	int mGetLifetime() const;
	int mGetSpeed() const;
	int mGetSize() const;
	int mGetPierceAmount() const;
	int mGetBounceAmount() const;
	int mGetCriticalMultiplier() const;
	int mGetCriticalChance() const;

	int mGetRotation() const;
	int mGetVelocityX() const;
	int mGetVelocityY() const;
	int mGetPositionX() const;
	int mGetPositionY() const;

	// Setters
	void mSetName(const std::string name);;
	void mSetDamage(const int damage);
	void mSetLifetime(const int lifetime);
	void mSetSpeed(const int speed);
	void mSetSize(const int size);
	void mSetPierceAmount(const int pierceAmount);
	void mSetBounceAmount(const int bounceAmount);
	void mSetCriticalMultiplier(const int criticalMultiplier);
	void mSetCriticalChance(const int criticalChance);
	
	void mSetRotation(const int rot);
	void mSetVelocityX(const int velX);
	void mSetVelocityY(const int velY);
	void mSetPositionX(const int posX);
	void mSetPositionY(const int posY);
	
	void mSetProjectile(std::string name, int damage, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance);

	// Autres
	void mInitializeMovement(const int rotation, const int speed);
	void mCloneFromAbility(const Abilities& ability);
	void mCastProjectile(const Projectile& projectile);
};