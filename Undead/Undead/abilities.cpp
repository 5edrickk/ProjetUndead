#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_name = "Default";
	_active = false;
	_damage = 5;
	_maxCooldown = 0.25 * (1000 / UPDATE_RATE); // Max cooldown in seconds (X * (1000 / UPDATE_RATE))
	_cooldown = 0;
	_speed = 1 * UPDATE_RATE; // Speed in pixels per seconds (X * UPDATE_RATE)
	_lifetime = 2 * (1000 / UPDATE_RATE); // Lifetime in seconds (X * (1000 / UPDATE_RATE))
	_size = 20; // Pixels
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100
}

Abilities::Abilities(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_name = name;
	_active = active;
	_damage = damage;
	_maxCooldown = maxCooldown;
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
	_active = false;
	_damage = 0;
	_maxCooldown = 0;
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
string Abilities::mGetName() const
{
	return _name;
}

bool Abilities::mGetActive() const
{
	return _active;
}

int Abilities::mGetDamage() const
{
	return _damage;
}

int Abilities::mGetMaxCooldown() const
{
	return _maxCooldown;
}

int Abilities::mGetCooldown() const
{
	return _cooldown;
}

int Abilities::mGetLifetime() const
{
	return _lifetime;
}

int Abilities::mGetSpeed() const
{
	return _speed;
}

int Abilities::mGetSize() const
{
	return _size;
}

int Abilities::mGetPierceAmount() const
{
	return _pierceAmount;
}

int Abilities::mGetBounceAmount() const
{
	return _bounceAmount;
}

int Abilities::mGetCriticalMultiplier() const
{
	return _criticalMultiplier;
}

int Abilities::mGetCriticalChance() const
{
	return _criticalChance;
}

//========================================================================================================================
// Setters
void Abilities::mSetName(const string name)
{
	_name = name;
}

void Abilities::mSetActive(const bool active)
{
	_active = active;
}

void Abilities::mSetDamage(const int damage)
{
	_damage = damage;
}

void Abilities::mSetMaxCooldown(const int maxCooldown)
{
	_maxCooldown = maxCooldown;
}

void Abilities::mSetCooldown(const int cooldown)
{
	_cooldown = cooldown;
}

void Abilities::mSetLifetime(const int lifetime)
{
	_lifetime = lifetime;
}

void Abilities::mSetSpeed(const int speed)
{
	_speed = speed;
}


void Abilities::mSetSize(const int size)
{
	_size = size;
}

void Abilities::mSetPierceAmount(const int pierceAmount)
{
	_pierceAmount = pierceAmount;
}

void Abilities::mSetBounceAmount(const int bounceAmount)
{
	_bounceAmount = bounceAmount;
}

void Abilities::mSetCriticalMultiplier(const int criticalMultiplier)
{
	_criticalMultiplier = criticalMultiplier;
}

void Abilities::mSetCriticalChance(const int criticalChance)
{
	_criticalChance = criticalChance;
}
