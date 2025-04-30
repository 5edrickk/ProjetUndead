#pragma once

#include <string>

#include "constantes.h"
#include "abilities.h"

class Projectile {
private:
	std::string _name;
	bool _active,
		_projectile;
	int _damage,
		_maxCooldown,
		_cooldown,
		_maxLifetime,
		_lifetime,
		_speed,
		_size,
		_maxPierceAmount,
		_pierceAmount,
		_maxBounceAmount,
		_bounceAmount,
		_criticalMultiplier,
		_criticalChance;

public:
	// Constructeurs
	Projectile();
	Projectile(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int maxLifetime, int lifetime, int speed, int size, int maxPierceAmount, int pierceAmount, int maxBounceAmount, int bounceAmount, int criticalMultiplier, int criticalChance);
	~Projectile();

	// Getters
	std::string mGetName() const;
	bool mGetProjectile() const;
	int mGetDamage() const;
	int mGetMaxLifetime() const;
	int mGetLifetime() const;
	int mGetSpeed() const;
	int mGetSize() const;
	int mGetMaxPierceAmount() const;
	int mGetPierceAmount() const;
	int mGetMaxBounceAmount() const;
	int mGetBounceAmount() const;
	int mGetCriticalMultiplier() const;
	int mGetCriticalChance() const;

	// Setters
	void mSetName(const std::string name);
	void mSetActive(const bool active);
	void mSetProjectile(const bool projectile);
	void mSetDamage(const int damage);
	void mSetMaxCooldown(const int maxCooldown);
	void mSetCooldown(const int cooldown);
	void mSetMaxLifetime(const int maxLifetime);
	void mSetLifetime(const int lifetime);
	void mSetSpeed(const int speed);
	void mSetSize(const int size);
	void mSetMaxPierceAmount(const int maxPierceAmount);
	void mSetPierceAmount(const int pierceAmount);
	void mSetMaxBounceAmount(const int maxBounceAmount);
	void mSetBounceAmount(const int bounceAmount);
	void mSetCriticalMultiplier(const int criticalMultiplier);
	void mSetCriticalChance(const int criticalChance);
	void mSetProjectile(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int maxLifetime, int lifetime, int speed, int size, int maxPierceAmount, int pierceAmount, int maxBounceAmount, int bounceAmount, int criticalMultiplier, int criticalChance);
	
	// Autres
	void mCloneFromAbility(const Abilities& ability);
};