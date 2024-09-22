#include "grasspatch.h"


grasspatch::grasspatch(int id,double x, double y, double length, sf::Color color):node(x, y, id)
{
	this->shape.setRadius(length);
	this->shape.setFillColor(color);
}
