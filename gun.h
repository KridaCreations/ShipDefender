#pragma once

#include "node.h"
#include "sceneManager.h"
#include <SFML/Graphics.hpp>
class gun : public node
{
public:
	sf::RectangleShape shape;
	gun(double x, double y,double length = 0,double width = 0, sf::Color color = sf::Color(0, 0, 0));

	void draw(sf::RenderWindow& window);
	void process(double delta);
	void lookat(double x,double y);
	gun() = delete;
};

