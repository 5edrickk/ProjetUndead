#pragma once

#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>
#include <iostream>

class Enemy {
private:
	sf::Color _color;
	std::string _name;
	int _ID,
		_maximumWave,
		_minimumWave,
		_maxHealth,
		_health,
		_speed,
		_damage,
		_spawnWeight,
		_dmgEffectCooldown,

		_direction,
		_rotation,
		_velocityX,
		_velocityY,
		_positionX,
		_positionY,

		_animationCooldown,
		_animationPosition,
		_spriteSheetID;

public:
	// Constructeurs
	Enemy();
	~Enemy();

	// Getters
	sf::Color mGetColor() const;
	std::string mGetName() const;
	int mGetID() const;
	int mGetMaximumWave() const;
	int mGetMinimumWave() const;
	int mGetMaxHealth() const;
	int mGetHealth() const;
	int mGetSpeed() const;
	int mGetDamage() const;
	int mGetSpawnWeight() const;
	int mGetDmgEffectCooldown() const;

	int mGetDirection() const;
	int mGetRotation() const;
	int mGetVelocityX() const;
	int mGetVelocityY() const;
	int mGetPositionX() const;
	int mGetPositionY() const;

	int mGetAnimationCooldown() const;
	int mGetAnimationPosition() const;
	int mGetSpriteSheetID() const;

	// Setters
	void mSetColor(const sf::Color color);
	void mSetName(const std::string name);
	void mSetID(const int ID);
	void mSetMaximumWave(const int maximumWave);
	void mSetMinimumWave(const int minimumWave);
	void mSetMaxHealth(const int maxHealth);
	void mSetHealth(const int health);
	void mSetSpeed(const int speed);
	void mSetDamage(const int damage);
	void mSetSpawnWeight(const int weight);
	void mSetDmgEffectCooldown(const int cooldown);

	void mSetDirection(const int dir);
	void mSetRotation(const int rot);
	void mSetVelocityX(const int x);
	void mSetVelocityY(const int y);
	void mSetPositionX(const int x);
	void mSetPositionY(const int y);

	void mSetAnimationCooldown(const int cooldown);
	void mSetAnimationPosition(const int position);
	void mSetSpriteSheetID(const int ID);

	// Autres
	void mInitializeMovement(const int playerX, const int playerY);
	void mDamageEffect(sf::RectangleShape& enemyShape);
	void mDamageEffectTick(sf::RectangleShape& enemyShape);
	void mSetEnemyType(int type, sf::RectangleShape& enemyShape);

};