#pragma once

// Options
#define DEBUG false
#define SHOW_SETTINGS_ON_DEBUG false
#define CLEAR_CONSOLE_ON_TICK false
#define PROJECTILE_DEBUG false

// Window
#define GAME_NAME "Undead"
#define WINDOW_SIZE_X 800
#define WINDOW_SIZE_Y 640
#define INCREMENT 0.5 //16
#define FRAMERATE 60 // FPS
#define UPDATE_RATE (1000 / 60) // FPS : milisecondes (50.0f = 20 times per second (1000/X.0f))

#define BACKGROUND_NUMBER 5

// Character
#define PLAYER_SIZE 32
#define PLAYER_ABILITY_SLOTS 5
#define PLAYER_MAX_HEALTH 100
#define PLAYER_SPEED 10

// Game
#define MAX_ENEMIES 100
#define MAX_PROJECTILES 100