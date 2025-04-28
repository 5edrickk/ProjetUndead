#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Background
{
private:
	sf::RectangleShape _background;
	sf::Texture _texture;
public:
	// Constructeurs
	Background();
	~Background();

	// Getters
	sf::RectangleShape getBackground() const;
	sf::Texture getTexture() const;

	// Setters
	void setBackground(const sf::RectangleShape& background);
	void setTexture(const sf::Texture& texture, const int left, const int top, const int width, const int height);
	void setPosition(const int x, const int y);

	// Autres
	void loadBackground(const std::string& path);
	void draw(sf::RenderWindow& window);
};

