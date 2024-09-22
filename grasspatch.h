#pragma once
#include "node.h"
#include <SFML/Graphics.hpp>
class grasspatch: public node
{
public:
	sf::CircleShape shape;
	grasspatch(int id,double x,double y,double length = 0, sf::Color color = sf::Color(100, 250, 50));

	grasspatch() = delete;
};

