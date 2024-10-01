#include "gun.h"
#include <iostream>



gun::gun(double x, double y, double length, double width, sf::Color color) :node(x, y)
{
	this->shape.setOrigin(0,width/2);
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(length,width));
	this->shape.setFillColor(color);
}

void gun::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

void gun::process(double delta)
{
	sceneManager* scene = sceneManager::getInstance();
	sf::Vector2i mlocalpos = sf::Mouse::getPosition(*(scene->window));
	system("CLS");
	//std::cout << "current mouse pos " << mlocalpos.x << " " << mlocalpos.y << std::endl;
	//this->shape.setRotation(((int)(this->shape.getRotation()) + 10) % 360);
	//this->shape.setRotation(45);
	lookat(mlocalpos.x, mlocalpos.y);
}

void gun::lookat(double x, double y)
{
	double relx = x - this->shape.getPosition().x;
	double rely = y - this->shape.getPosition().y;
	std::cout << relx << " " << rely << std::endl;

	double dotproduct = (relx * 1) + (rely * 0);
	double length = (relx * relx) + (rely * rely);

	length = std::sqrt(length);
	dotproduct = dotproduct / (length);
	//std::cout << dotproduct << std::endl;
	double angle = acos(dotproduct);
	double indegreeangle = (angle * (180.0)) / 3.14;
	if (rely < 0)
	{
		indegreeangle = 360 - indegreeangle;
	}
	std::cout << "angle is " << indegreeangle << " dotproduct " << dotproduct << " angle " << (angle) << std::endl;
	this->shape.setRotation(indegreeangle);
}


