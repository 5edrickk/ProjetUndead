#pragma once

// Options
#define DEBUG false
#define SHOW_SETTINGS_ON_DEBUG false
#define CLEAR_CONSOLE_ON_TICK false
#define PROJECTILE_DEBUG false

// Window
#define GAME_NAME "Undead"
#define WINDOW_SIZE_X 1300
#define WINDOW_SIZE_Y 900
#define INCREMENT 2
#define FRAMERATE 60 // FPS
#define UPDATE_RATE 60 // FPS : milisecondes (50.0f = 20 times per second (1000/X.0f))

#define BACKGROUND_NUMBER 5

// Character
#define PLAYER_SIZE 32
#define PLAYER_ABILITY_SLOTS 3
#define PLAYER_MAX_HEALTH 500
#define PLAYER_SPEED 10
#define PLAYER_MAX_UPGRADE_LEVEL 10
#define PLAYER_UPGRADE_TYPE_NUMBER 2

// Game
#define MAX_ENEMIES 100
#define MAX_PROJECTILES 100
#define MAX_SPAWN_COOLDOWN 100
#define KILLS_FOR_WAVE 5

// Enemies
#define DAMAGE_FRAME_TIME 10
#define ENEMY_TYPE_NUMBER 3