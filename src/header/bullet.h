#pragma once
#include "node.h"
#include "sceneManager.h"
#include <SFML/Graphics.hpp>
class bullet : public node
{
public:
	sf::RectangleShape shape;
	
	bullet(double x, double y, sf::Vector2f direction,double speed, sf::Color color = sf::Color(252, 7, 3));
	sf::Vector2f direction;
	double speed;
	void draw(sf::RenderWindow& window);
	void process(double delta);
	void lookat(double x, double y);
	sf::Clock Clock;

	bullet() = delete;

};

