#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_name = "Default";
	_active = false;
	_damage = 5;
	_cooldown = UPDATE_RATE * 0.5; // Cooldown in seconds (UPDATE_RATE * X)
	_speed = 50 / UPDATE_RATE; // Pixels per seconds (X / UPDATE_RATE)
	_lifetime = UPDATE_RATE * 2; // Lifetime in seconds (UPDATE_RATE * X)
	_size = 20; // Pixels
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100
}

Abilities::Abilities(std::string name, bool active, int damage, int cooldown, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_name = name;
	_active = active;
	_damage = damage;
	_cooldown = cooldown;
	_speed = speed;
	_lifetime = lifetime;
	_size = size;
	_pierceAmount = pierceAmount;
	_bounceAmount = bounceAmount;
	_criticalMultiplier = criticalMultiplier;
	_criticalChance = criticalChance;
}

Abilities::~Abilities()
{
	_name = "";
	_damage = 0;
	_cooldown = 0;
	_speed = 0;
	_lifetime = 0;
	_size = 0;
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 0;
	_criticalChance = 0;
}

//========================================================================================================================
// Getters
bool Abilities::mGetActive() const
{
	return _active;
}

//========================================================================================================================
// Setters
void Abilities::mSetAvtive(const int active)
{
	_active = active;
}