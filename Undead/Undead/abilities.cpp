#include "abilities.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Abilities::Abilities()
{
	_upgradeName = "Default";
	_upgradeText = "Default text";
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
	_upgradeName = "";
	_upgradeText = "";
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
std::string Abilities::mGetUpgradeName() const
{
	return _upgradeName;
}

std::string Abilities::mGetUpgradeText() const
{
	return _upgradeText;
}

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
void Abilities::mSetUpgradeName(const std::string upgradeName)
{
	_upgradeName = upgradeName;
}

void Abilities::mSetUpgradeText(const std::string upgradeText)
{
	_upgradeText = upgradeText;
}

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
		mSetUpgradeName("Throwing knives");
		switch (level)
		{
		case 1:

			mSetUpgradeText("Balanced starter weapon");
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

			mSetUpgradeText("Reduced cooldown and increaased speed");
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

			mSetUpgradeText("Even more reduced cooldown and increaased speed");
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

			mSetUpgradeText("Increased damage and projectile lifetime");
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

			mSetUpgradeText("Reduced cooldown and increased speed");
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

			mSetUpgradeText("Pierces through one enemy, gains increased projectile lifetime and size");
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

			mSetUpgradeText("Increased damage, shorter cooldown and increased speed");
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

			mSetUpgradeText("Pierces through a second enemy and gains increased projectile size");
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

			mSetUpgradeText("Gains increased damage, shorter cooldown and increased speed");
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

			mSetUpgradeText("Gains even more damage, shorter cooldown and increased speed");
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

			break;

		}
		break;

	case 2:
		mSetUpgradeName("Corruption aura");
		switch (level)
		{
		case 1:

			mSetUpgradeText("Periodic damaging aura around the player");
			mSetDamage(1);
			mSetMaxCooldown(10);
			mSetSpeed(0);
			mSetLifetime(10);
			mSetSize(70); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 2:

			mSetUpgradeText("Increased area");
			mSetDamage(1);
			mSetMaxCooldown(10);
			mSetSpeed(0);
			mSetLifetime(10);
			mSetSize(90); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 3:

			mSetUpgradeText("Even larger area");
			mSetDamage(1);
			mSetMaxCooldown(10);
			mSetSpeed(0);
			mSetLifetime(10);
			mSetSize(110); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 4:

			mSetUpgradeText("Increases area and shortens cooldown");
			mSetDamage(1);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(130); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 5:

			mSetUpgradeText("Increases area and damage");
			mSetDamage(2);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(150); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 6:

			mSetUpgradeText("Increases area even more");
			mSetDamage(2);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(180); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 7:

			mSetUpgradeText("Increases area and damage");
			mSetDamage(3);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(200); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 8:

			mSetUpgradeText("Increases area");
			mSetDamage(3);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(230); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 9:

			mSetUpgradeText("Increases area and damage");
			mSetDamage(4);
			mSetMaxCooldown(7);
			mSetSpeed(0);
			mSetLifetime(7);
			mSetSize(250); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 10:

			mSetUpgradeText("Increases area and shortens cooldown");
			mSetDamage(4);
			mSetMaxCooldown(5);
			mSetSpeed(0);
			mSetLifetime(5);
			mSetSize(280); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(0);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		default:

			break;

		}
		break;

	case 3:
		mSetUpgradeName("Prism");
		switch (level)
		{
		case 1:

			mSetDamage(10);
			mSetMaxCooldown(120);
			mSetSpeed(4);
			mSetLifetime(240);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(1);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 2:

			mSetDamage(15);
			mSetMaxCooldown(120);
			mSetSpeed(4);
			mSetLifetime(320);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(1);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 3:

			mSetDamage(15);
			mSetMaxCooldown(120);
			mSetSpeed(6);
			mSetLifetime(320);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(1);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 4:

			mSetDamage(15);
			mSetMaxCooldown(100);
			mSetSpeed(6);
			mSetLifetime(420);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(2);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 5:

			mSetDamage(15);
			mSetMaxCooldown(100);
			mSetSpeed(8);
			mSetLifetime(420);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(2);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 6:

			mSetDamage(20);
			mSetMaxCooldown(100);
			mSetSpeed(8);
			mSetLifetime(420);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(2);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 7:

			mSetDamage(20);
			mSetMaxCooldown(80);
			mSetSpeed(8);
			mSetLifetime(480);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(2);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 8:

			mSetDamage(20);
			mSetMaxCooldown(80);
			mSetSpeed(10);
			mSetLifetime(560);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(3);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 9:

			mSetDamage(30);
			mSetMaxCooldown(80);
			mSetSpeed(12);
			mSetLifetime(560);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(3);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		case 10:

			mSetDamage(30);
			mSetMaxCooldown(70);
			mSetSpeed(12);
			mSetLifetime(680);
			mSetSize(30); // Pixels
			mSetPierceAmount(MAX_ENEMIES);
			mSetBounceAmount(4);
			mSetCriticalMultiplier(50); // %100
			mSetCriticalChance(5); // %100
			break;

		default:

			break;

		}
		break;

	default:

		break;

	}
}
