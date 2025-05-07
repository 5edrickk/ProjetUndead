#pragma once

#include <string>

#include "constantes.h"

class Abilities {
private:
	std::string _name;
	bool _active;
	int _damage,
		_maxCooldown,
		_cooldown,
		_lifetime,
		_speed,
		_size,
		_pierceAmount,
		_bounceAmount,
		_criticalMultiplier,
		_criticalChance,
		_level;

public:
	// Constructeurs
	Abilities();
	~Abilities();

	// Getters
	std::string mGetName() const;
	bool mGetActive() const;
	int mGetDamage() const;
	int mGetMaxCooldown() const;
	int mGetCooldown() const;
	int mGetLifetime() const;
	int mGetSpeed() const;
	int mGetSize() const;
	int mGetPierceAmount() const;
	int mGetBounceAmount() const;
	int mGetCriticalMultiplier() const;
	int mGetCriticalChance() const;
	int mGetLevel() const;

	// Setters
	void mSetName(const std::string name);
	void mSetActive(const bool active);
	void mSetDamage(const int damage);
	void mSetMaxCooldown(const int maxCooldown);
	void mSetCooldown(const int cooldown);
	void mSetLifetime(const int lifetime);
	void mSetSpeed(const int speed);
	void mSetSize(const int size);
	void mSetPierceAmount(const int pierceAmount);
	void mSetBounceAmount(const int bounceAmount);
	void mSetCriticalMultiplier(const int criticalMultiplier);
	void mSetCriticalChance(const int criticalChance);
	void mSetLevel(const int level);

	// Autres
	void mSetAbilityType(std::string name, int slot, int level);
};