#include "projectile.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Projectile::Projectile()
{
	_name = "Default";
	_damage = 5;
	_speed = 50 / UPDATE_RATE; // Pixels per seconds (X / UPDATE_RATE)
	_lifetime = UPDATE_RATE * 2; // Lifetime in seconds (UPDATE_RATE * X)
	_size = 20; // Pixels
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100

	_rotation = 0;
	_velocityX = 0;
	_velocityY = 0;
}

Projectile::Projectile(std::string name, int damage, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_name = name;
	_damage = damage;
	_speed = speed;
	_lifetime = lifetime;
	_size = size;
	_pierceAmount = pierceAmount;
	_bounceAmount = bounceAmount;
	_criticalMultiplier = criticalMultiplier;
	_criticalChance = criticalChance;
}

Projectile::~Projectile()
{
	_name = "";
	_damage = 0;
	_speed = 0;
	_lifetime = 0;
	_size = 0;
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 0;
	_criticalChance = 0;

	_rotation = 0;
	_velocityX = 0;
	_velocityY = 0;
}

//========================================================================================================================
// Getters
string Projectile::mGetName() const
{
	return _name;
}

int Projectile::mGetDamage() const
{
	return _damage;
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

int Projectile::mGetPierceAmount() const
{
	return _pierceAmount;
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

int Projectile::mGetRotation() const
{
	return _rotation;
}

int Projectile::mGetVelocityX() const
{
	return _velocityX;
}

int Projectile::mGetVelocityY() const
{
	return _velocityY;
}

int Projectile::mGetPositionX() const
{
	return _positionX;
}

int Projectile::mGetPositionY() const
{
	return _positionY;
}

//========================================================================================================================
// Setters
void Projectile::mSetName(const string name)
{
	_name = name;
}

void Projectile::mSetDamage(const int damage)
{
	_damage = damage;
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

void Projectile::mSetPierceAmount(const int pierceAmount)
{
	_pierceAmount = pierceAmount;
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

void Projectile::mSetRotation(const int rot)
{
	_rotation = rot;
}

void Projectile::mSetVelocityX(const int velX)
{
	_velocityX = velX;
}

void Projectile::mSetVelocityY(const int velY)
{
	_velocityY = velY;
}

void Projectile::mSetPositionX(const int posX)
{
	_positionX = posX;
}

void Projectile::mSetPositionY(const int posY)
{
	_positionY = posY;
}

void Projectile::mSetProjectile(std::string name, int damage, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_name = name;
	_damage = damage;
	_speed = speed;
	_lifetime = lifetime;
	_size = size;
	_pierceAmount = pierceAmount;
	_bounceAmount = bounceAmount;
	_criticalMultiplier = criticalMultiplier;
	_criticalChance = criticalChance;
}

//========================================================================================================================
// Autres
void Projectile::mInitializeMovement(const int rotation, const int speed)
{
	float rads = rotation * (3.141592653589793 / 180);

	mSetRotation(rotation);

	mSetVelocityX(speed * (cos(rads)));
	mSetVelocityY(speed * (sin(rads)));

	fDebug(12);
	fDebug(8, rotation);
	fDebug(9, mGetVelocityX());
	fDebug(10, mGetVelocityY());
}

void Projectile::mCloneFromAbility(const Abilities& ability)
{
	_name = ability.mGetName();
	_damage = ability.mGetDamage();
	_speed = ability.mGetSpeed();;
	_lifetime = ability.mGetLifetime();
	_size = ability.mGetSize();
	_pierceAmount = ability.mGetPierceAmount();
	_bounceAmount = ability.mGetBounceAmount();
	_criticalMultiplier = ability.mGetCriticalMultiplier();
	_criticalChance = ability.mGetCriticalChance();
}

void Projectile::mCastProjectile(const Projectile& projectile)
{

}
