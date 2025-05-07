#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_active = false;
	_ID = 0;
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
	_level = 0;
}

Abilities::~Abilities()
{
	_ID = 0;
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
bool Abilities::mGetActive() const
{
	return _active;
}

int Abilities::mGetID() const
{
	return _ID;
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
void Abilities::mSetActive(const bool active)
{
	_active = active;
}

void Abilities::mSetID(const int ID)
{
	_ID = ID;
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
void Abilities::mSetAbilityType(int ID, int slot, int level)
{
	switch (ID)
	{
	case 1:

		switch (level)
		{
		case 1:

			mSetDamage(5);
			mSetMaxCooldown(30);
			mSetSpeed(6);
			mSetLifetime(60);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 2:

			mSetDamage(5);
			mSetMaxCooldown(25);
			mSetSpeed(8);
			mSetLifetime(60);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 3:

			mSetDamage(5);
			mSetMaxCooldown(20);
			mSetSpeed(10);
			mSetLifetime(60);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 4:

			mSetDamage(10);
			mSetMaxCooldown(20);
			mSetSpeed(10);
			mSetLifetime(90);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 5:

			mSetDamage(10);
			mSetMaxCooldown(15);
			mSetSpeed(12);
			mSetLifetime(90);
			mSetSize(20); // Pixels
			mSetPierceAmount(0);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 6:

			mSetDamage(10);
			mSetMaxCooldown(15);
			mSetSpeed(12);
			mSetLifetime(120);
			mSetSize(25); // Pixels
			mSetPierceAmount(1);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 7:

			mSetDamage(15);
			mSetMaxCooldown(10);
			mSetSpeed(14);
			mSetLifetime(120);
			mSetSize(25); // Pixels
			mSetPierceAmount(1);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 8:

			mSetDamage(15);
			mSetMaxCooldown(10);
			mSetSpeed(14);
			mSetLifetime(120);
			mSetSize(30); // Pixels
			mSetPierceAmount(2);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(2); // %100
			break;

		case 9:

			mSetDamage(20);
			mSetMaxCooldown(7);
			mSetSpeed(16);
			mSetLifetime(120);
			mSetSize(30); // Pixels
			mSetPierceAmount(2);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(2); // %100
			break;

		case 10:

			mSetDamage(25);
			mSetMaxCooldown(5);
			mSetSpeed(18);
			mSetLifetime(120);
			mSetSize(30); // Pixels
			mSetPierceAmount(2);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(2); // %100
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
			break;

		}
		break;

	case 2:

		switch (level)
		{
		case 1:

			mSetDamage(1);
			mSetMaxCooldown(10);
			mSetSpeed(0);
			mSetLifetime(10);
			mSetSize(70); // Pixels
			mSetPierceAmount(1000);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		default:

			mSetDamage(1);
			mSetMaxCooldown(10);
			mSetSpeed(0);
			mSetLifetime(10);
			mSetSize(70); // Pixels
			mSetPierceAmount(1000);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		}
		break;

	default:

		break;

	}
}
