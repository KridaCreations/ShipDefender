#pragma once
#include "node.h"
#include <SFML/Graphics.hpp>
class spaceship: public node
{
public:
	sf::CircleShape shape;
	int health = 100;
	int MAX_HEALTH = 100;
	spaceship(double x,double y,double length = 0, sf::Color color = sf::Color(100, 250, 50));
	
	void draw(sf::RenderWindow& window);
	void process(double delta);
	spaceship() = delete;
	void takedamage(int damage);

};

