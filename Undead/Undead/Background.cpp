#include "player.h"
#include "Background.h"

using namespace sf;
using namespace std;

Background::Background()
{
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(WINDOW_SIZE_X, WINDOW_SIZE_Y));
	_background.setFillColor(Color::White);
	_background.setOutlineColor(Color::Black);
	_background.setOutlineThickness(5);

}

Background::~Background()
{
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(0, 0));
	_background.setFillColor(Color::White);
	_background.setOutlineColor(Color::Black);
	_background.setOutlineThickness(0);
}

sf::RectangleShape Background::getBackground() const
{
	return _background;
}

sf::Texture Background::getTexture() const
{
	if (_texture.getSize().x != 0 && _texture.getSize().y != 0)
	{
		return _texture;
	}
	else
	{
		cout << "Erreur : la texture n'est pas chargée" << endl;
	}
}

void Background::setBackground(const sf::RectangleShape& background)
{
	_background = background;
	_background.setPosition(0, 0);
	_background.setSize(Vector2f(WINDOW_SIZE_X, WINDOW_SIZE_Y));
	_background.setFillColor(Color::White);
	_background.setOutlineColor(Color::Black);
	_background.setOutlineThickness(5);
}

void Background::setTexture(const sf::Texture& texture,int left, int top, int width, int height)
{
	_texture = texture;
	_background.setTexture(&_texture);
	_background.setTextureRect(IntRect(left, top, width, height));
}

void Background::setPosition(const int x, const int y)
{
	_background.setPosition(x, y);
}

void Background::loadBackground(const std::string& path)
{
	if (!_texture.loadFromFile(path))
	{
		cout << "Erreur de chargement de la texture" << endl;
	}
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(_background);
}
