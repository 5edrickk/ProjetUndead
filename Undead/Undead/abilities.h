#pragma once

#include <string>

#include "constantes.h"

class Abilities {
private:
	std::string _name;
	bool _active;
	int _damage,
		_cooldown,
		_lifetime,
		_speed,
		_size,
		_pierceAmount,
		_bounceAmount,
		_criticalMultiplier,
		_criticalChance;

public:
	// Constructeurs
	Abilities();
	Abilities(std:: string name, bool active, int damage, int cooldown, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance);
	~Abilities();

	// Getters
	bool mGetActive() const;

	// Setters
	void mSetAvtive(const int active);
};