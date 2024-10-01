#include "bullet.h"


bullet::bullet(double x, double y,sf::Vector2f direction,double speed, sf::Color color):node(x,y)
{
	double len = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	direction.x = direction.x / len;
	direction.y = direction.y / len;
	this->direction = direction;
	this->speed = speed;
	this->shape.setOrigin(5,5);
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(10,10));
	this->shape.setFillColor(color);
	this->Clock.restart();
}

void bullet::draw(sf::RenderWindow& window)
{
	//std::cout << "draw in bullet called "<<this->nodeid << std::endl;
	window.draw(this->shape);
}

void bullet::process(double delta)
{
	sf::Vector2f pos = this->shape.getPosition();
	pos.x = pos.x + (this->direction.x * speed * delta);
	pos.y = pos.y + (this->direction.y * speed * delta);
	this->shape.setPosition(pos.x, pos.y);
	if (this->Clock.getElapsedTime().asSeconds() > 3)
	{
		std::cout << "deleting bullet id "<<this->nodeid<<" \n ";
		sceneManager::getInstance()->toremove.push_back(this);
	}
}

void bullet::lookat(double x, double y)
{

}