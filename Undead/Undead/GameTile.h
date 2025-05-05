#pragma once

class GameTile
{
private:
	Vector2f _position;
	Texture _texture;
	Sprite _sprite;

	bool _isPassable;
	bool _isExit;

public:
	GameTile(std::string&, float, float, bool, bool);

	bool setUpSprite(std::string path);
};