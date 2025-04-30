#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_name = "Default";
	_active = false;
	_projectile = false;
	_damage = 5;
	_maxCooldown = UPDATE_RATE * 0.5; // Max cooldown in seconds (UPDATE_RATE * X)
	_cooldown = 0;
	_speed = 50 / UPDATE_RATE; // Pixels per seconds (X / UPDATE_RATE)
	_maxLifetime = UPDATE_RATE * 2; // Lifetime in seconds (UPDATE_RATE * X)
	_lifetime = UPDATE_RATE * 2; // Lifetime in seconds (UPDATE_RATE * X)
	_size = 20; // Pixels
	_maxPierceAmount = 0;
	_pierceAmount = 0;
	_maxBounceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100
}

Abilities::Abilities(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int maxLifetime, int lifetime, int speed, int size, int maxPierceAmount, int pierceAmount, int maxBounceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_name = name;
	_active = active;
	_projectile = projectile;
	_damage = damage;
	_maxCooldown = maxCooldown;
	_cooldown = cooldown;
	_speed = speed;
	_maxLifetime = maxLifetime;
	_lifetime = lifetime;
	_size = size;
	_maxPierceAmount = maxPierceAmount;
	_pierceAmount = pierceAmount;
	_maxBounceAmount = maxBounceAmount;
	_bounceAmount = bounceAmount;
	_criticalMultiplier = criticalMultiplier;
	_criticalChance = criticalChance;
}

Abilities::~Abilities()
{
	_name = "";
	_active = false;
	_projectile = false;
	_damage = 0;
	_maxCooldown = 0;
	_cooldown = 0;
	_speed = 0;
	_maxLifetime = 0;
	_lifetime = 0;
	_size = 0;
	_maxPierceAmount = 0;
	_pierceAmount = 0;
	_maxBounceAmount = 0;
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

bool Abilities::mGetProjectile() const
{
	return _projectile;
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

int Abilities::mGetMaxLifetime() const
{
	return _maxLifetime;
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

int Abilities::mGetMaxPierceAmount() const
{
	return _maxPierceAmount;
}

int Abilities::mGetPierceAmount() const
{
	return _pierceAmount;
}

int Abilities::mGetMaxBounceAmount() const
{
	return _maxBounceAmount;
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

void Abilities::mSetProjectile(const bool projectile)
{
	_projectile = projectile;
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

void Abilities::mSetMaxLifetime(const int maxLifetime)
{
	_maxLifetime = maxLifetime;
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

void Abilities::mSetMaxPierceAmount(const int maxPierceAmount)
{
	_maxPierceAmount = maxPierceAmount;
}

void Abilities::mSetPierceAmount(const int pierceAmount)
{
	_pierceAmount = pierceAmount;
}

void Abilities::mSetMaxBounceAmount(const int maxBounceAmount)
{
	_maxBounceAmount = maxBounceAmount;
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
