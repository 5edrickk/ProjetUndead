#include "game.h"
#include "Camera.h"

using namespace std;
using namespace sf;


Camera::Camera()
{
	_position = sf::Vector2f(0, 0);
	_zoomLevel = 1.0f;
	_rotation = 0.0f;
	_view.setSize(800, 600); // Set the view size
	_view.setCenter(_position); // Set the view center
	_view.setRotation(_rotation); // Set the view rotation
	_view.zoom(_zoomLevel); // Set the view zoom
}

Camera::Camera(float x, float y, float zoomLevel, float rotation)
{
	_position = sf::Vector2f(x, y);
	_zoomLevel = zoomLevel;
	_rotation = rotation;
	_view.setSize(800, 600); // Set the view size
	_view.setCenter(_position); // Set the view center
	_view.setRotation(_rotation); // Set the view rotation
	_view.zoom(_zoomLevel); // Set the view zoom
}

Camera::~Camera()
{
}

void Camera::mSetPosition(float x, float y)
{
	_position.x = x;
	_position.y = y;
}

void Camera::msetViewPort(float left, float top, float width, float height)
{
	_view.setViewport(sf::FloatRect(left, top, width, height));
}

sf::View Camera::mGetView() const
{
	return _view;
}

sf::Vector2f Camera::mGetPosition() const
{
	if (_position.x != 0 && _position.y != 0)
	{
		return _position;
	}

}

float Camera::mGetZoom() const
{
	return _zoomLevel;
}

sf::Vector2f Camera::mGetSize() const
{
	if (_view.getSize().x != 0 && _view.getSize().y != 0)
	{
		return _view.getSize();
	}
}

void Camera::mUpdate()
{
	_view.setCenter(_position);
	//_view.zoom(_zoomLevel);
	//_view.setSize(800 / _zoomLevel, 600 / _zoomLevel); // Adjust the view size based on zoom level
}

void Camera::mUpdateZoom()
{
	_view.zoom(_zoomLevel);
}

void Camera::mSetZoom(float zoomLevel)
{
	_zoomLevel = zoomLevel;

}

void Camera::mSetRotation(float angle)
{
	_rotation = angle;
}

float clamp(float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}
	else if (value > max)
	{
		return max;
	}
	return value;
}
