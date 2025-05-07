#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

#include "game.h"
#include "GameTile.h"

using namespace std;
using namespace sf;



GameTile::GameTile(string textureName, float x, float y, bool passable, bool exit)
{
	// Load the texture from a file
	if (!setUpSprite(textureName)){ 
		cout << "Error loading texture" << endl;	
		return;
	}
	_position = Vector2f(x, y);
	_sprite.setPosition(_position);
	_isPassable = passable;
	_isExit = exit;
}

bool GameTile::setUpSprite(std::string path)
{
	// Load the texture from a file
	if (!_texture.loadFromFile("path"))
	{
		cout << "Error loading texture" << endl;
		return false;
	}
	// Set the texture to the sprite
	_texture.setSmooth(true); // Enable smooth scaling
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(IntRect(0, 0, 100, 80)); // Set the texture rectangle
	return true;
}
