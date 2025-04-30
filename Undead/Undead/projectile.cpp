#include "projectile.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Projectile::Projectile()
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

Projectile::Projectile(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int maxLifetime, int lifetime, int speed, int size, int maxPierceAmount, int pierceAmount, int maxBounceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
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

Projectile::~Projectile()
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
string Projectile::mGetName() const
{
	return _name;
}

bool Projectile::mGetProjectile() const
{
	return _projectile;
}

int Projectile::mGetDamage() const
{
	return _damage;
}

int Projectile::mGetMaxLifetime() const
{
	return _maxLifetime;
}

int Projectile::mGetLifetime() const
{
	return _lifetime;
}

int Projectile::mGetSpeed() const
{
	return _speed;
}

int Projectile::mGetSize() const
{
	return _size;
}

int Projectile::mGetMaxPierceAmount() const
{
	return _maxPierceAmount;
}

int Projectile::mGetPierceAmount() const
{
	return _pierceAmount;
}

int Projectile::mGetMaxBounceAmount() const
{
	return _maxBounceAmount;
}

int Projectile::mGetBounceAmount() const
{
	return _bounceAmount;
}

int Projectile::mGetCriticalMultiplier() const
{
	return _criticalMultiplier;
}

int Projectile::mGetCriticalChance() const
{
	return _criticalChance;
}

//========================================================================================================================
// Setters
void Projectile::mSetName(const string name)
{
	_name = name;
}

void Projectile::mSetActive(const bool active)
{
	_active = active;
}

void Projectile::mSetProjectile(const bool projectile)
{
	_projectile = projectile;
}

void Projectile::mSetDamage(const int damage)
{
	_damage = damage;
}

void Projectile::mSetMaxCooldown(const int maxCooldown)
{
	_maxCooldown = maxCooldown;
}

void Projectile::mSetCooldown(const int cooldown)
{
	_cooldown = cooldown;
}

void Projectile::mSetMaxLifetime(const int maxLifetime)
{
	_maxLifetime = maxLifetime;
}

void Projectile::mSetLifetime(const int lifetime)
{
	_lifetime = lifetime;
}

void Projectile::mSetSpeed(const int speed)
{
	_speed = speed;
}


void Projectile::mSetSize(const int size)
{
	_size = size;
}

void Projectile::mSetMaxPierceAmount(const int maxPierceAmount)
{
	_maxPierceAmount = maxPierceAmount;
}

void Projectile::mSetPierceAmount(const int pierceAmount)
{
	_pierceAmount = pierceAmount;
}

void Projectile::mSetMaxBounceAmount(const int maxBounceAmount)
{
	_maxBounceAmount = maxBounceAmount;
}

void Projectile::mSetBounceAmount(const int bounceAmount)
{
	_bounceAmount = bounceAmount;
}

void Projectile::mSetCriticalMultiplier(const int criticalMultiplier)
{
	_criticalMultiplier = criticalMultiplier;
}

void Projectile::mSetCriticalChance(const int criticalChance)
{
	_criticalChance = criticalChance;
}

void Projectile::mSetProjectile(std::string name, bool active, bool projectile, int damage, int maxCooldown, int cooldown, int maxLifetime, int lifetime, int speed, int size, int maxPierceAmount, int pierceAmount, int maxBounceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
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

void Projectile::mCloneFromAbility(const Abilities& ability)
{
	_name = ability.mGetName();
	_projectile = true;
	_damage = ability.mGetDamage();
	_speed = ability.mGetSpeed();
	_maxLifetime = ability.mGetMaxLifetime();
	_lifetime = ability.mGetMaxLifetime();
	_size = ability.mGetSize();
	_maxPierceAmount = ability.mGetMaxPierceAmount();
	_pierceAmount = ability.mGetMaxPierceAmount();
	_maxBounceAmount = ability.mGetMaxBounceAmount();
	_bounceAmount = ability.mGetMaxBounceAmount();
	_criticalMultiplier = ability.mGetCriticalMultiplier();
	_criticalChance = ability.mGetCriticalChance();
}
