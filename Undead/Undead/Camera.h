#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Camera
{
private:
	sf::View _view;
	sf::Vector2f _position;
	float _zoomLevel;
	float _rotation;
public:
	Camera();
	Camera(float x, float y, float zoomLevel = 1.0f, float rotation = 0.0f);
	~Camera();

	void mSetPosition(float x, float y);
	void mSetZoom(float zoomLevel);
	void mSetRotation(float angle);
	void msetViewPort(float left, float top, float width, float height);

	sf::View mGetView() const;
	sf::Vector2f mGetPosition() const;
	float mGetZoom() const;
	float mGetRotation() const;
	sf::Vector2f mGetSize() const;
	


	void mUpdate();
	void mUpdateZoom();
};

float clamp(float value, float min, float max);

