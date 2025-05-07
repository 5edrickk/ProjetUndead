#pragma once

class GameTile
{
	public:
		sf::Vector2f _position;
		sf::Texture _texture;
		sf::Sprite _sprite;

		bool _isPassable;
		bool _isExit;
		GameTile(std::string, float, float, bool, bool);
		bool setUpSprite(std::string path);
}; 