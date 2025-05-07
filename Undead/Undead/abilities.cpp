#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_name = "Default";
	_active = false;
	_damage = 5;
	_maxCooldown = 30;
	_cooldown = 0;
	_speed = 6;
	_lifetime = 120;
	_size = 20; // Pixels
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100
	_level = 1;
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
	_level = 0;
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

int Abilities::mGetLevel() const
{
	return _level;
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

void Abilities::mSetLevel(const int level)
{
	_level = level;
}

//========================================================================================================================
// Autres
void Abilities::mSetAbilityType(std::string name, int slot, int level)
{
	if (name == "Default")
	{
		switch (level)
		{
		case 1:

			mSetDamage(5);
			mSetMaxCooldown(30);
			mSetSpeed(6);
			mSetLifetime(120);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			mSetLevel(level);
			break;

		case 2:

			mSetDamage(5);
			mSetMaxCooldown(25);
			mSetSpeed(8);
			mSetLifetime(120);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			mSetLevel(level);
			break;

		case 3:

			mSetDamage(5);
			mSetMaxCooldown(20);
			mSetSpeed(10);
			mSetLifetime(120);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			mSetLevel(level);
			break;

		case 4:

			mSetDamage(10);
			mSetMaxCooldown(20);
			mSetSpeed(10);
			mSetLifetime(120);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			mSetLevel(level);
			break;

		default:

			mSetDamage(5);
			mSetMaxCooldown(30);
			mSetSpeed(6);
			mSetLifetime(120);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			mSetLevel(level);
			break;

		}
	}
	else if (name == "Fireball")
	{

	}
	else
	{

	}
}
