#include "projectile.h"

using namespace std;

//========================================================================================================================
// Constructeurs
Projectile::Projectile()
{
	_canDamage = true;
	_damage = 1;
	_damage = 5;
	_speed = 10;
	_lifetime = 120;
	_size = 20; // Pixels
	_pierceAmount = 0;
	_bounceAmount = 0;
	_criticalMultiplier = 50; // %100
	_criticalChance = 5; // %100

	_rotation = 0;
	_velocityX = 0;
	_velocityY = 0;
	_positionX = 0;
	_positionY = 0;
}

Projectile::~Projectile()
{
	_canDamage = false;
	_damage = 0;
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
	_positionX = 0;
	_positionY = 0;
}

//========================================================================================================================
// Getters
bool Projectile::mGetCanDamage() const
{
	return _canDamage;
}

int Projectile::mGetID() const
{
	return _ID;
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
void Projectile::mSetCanDamage(const bool canDamage)
{
	_canDamage = canDamage;
}

void Projectile::mSetID(const int ID)
{
	_ID = ID;
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

void Projectile::mSetProjectile(int ID, int damage, int lifetime, int speed, int size, int pierceAmount, int bounceAmount, int criticalMultiplier, int criticalChance)
{
	_ID = ID;
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
	srand(time(0));
	float rads = rotation * (3.141592653589793 / 180);

	if (mGetID() == 2)
	{
		mSetRotation(0);

		mSetVelocityX(0);
		mSetVelocityY(0);
	}
	else if (mGetID() == 3)
	{
		int randomDirection = ((rand() % 8 + 0) * 45) * (3.141592653589793 / 180);

		mSetVelocityX(speed * (cos(randomDirection)));
		mSetVelocityY(speed * (sin(randomDirection)));
	}
	else
	{
		mSetRotation(rotation);
		
		mSetVelocityX(speed * (cos(rads)));
		mSetVelocityY(speed * (sin(rads)));
	}
}

void Projectile::mCloneFromAbility(const Abilities& ability)
{
	_ID = ability.mGetID();
	_damage = ability.mGetDamage();
	_speed = ability.mGetSpeed();;
	_lifetime = ability.mGetLifetime();
	_size = ability.mGetSize();
	_pierceAmount = ability.mGetPierceAmount();
	_bounceAmount = ability.mGetBounceAmount();
	_criticalMultiplier = ability.mGetCriticalMultiplier();
	_criticalChance = ability.mGetCriticalChance();
}
