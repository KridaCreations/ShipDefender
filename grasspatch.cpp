#include "grasspatch.h"
#include <iostream>



grasspatch::grasspatch(double x, double y, double length, sf::Color color):node(x, y)
{
	this->shape.setPosition(x, y);
	this->shape.setRadius(length);
	this->shape.setFillColor(color);
}

void grasspatch::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

void grasspatch::process(double delta)
{
	
}
