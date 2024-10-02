#include "../header/sceneManager.h"

enemy::enemy(double x, double y, int length,double speed,sf::Vector2f target, sf::Color color):node(x,y)
{
	this->shape.setOrigin((float)length, (float)length);
	this->shape.setPosition(x, y);
	this->speed = speed;
	this->health = length;
	this->target = target;
	this->shape.setRadius(length);
	this->shape.setOutlineThickness(2);
}

void enemy::process(double delta)
{
	sf::Vector2f pos = this->shape.getPosition();
	double dirx = this->target.x - pos.x;
	double diry = this->target.y - pos.y;
	double distance = std::sqrt((dirx * dirx) + (diry * diry));
	dirx = dirx / distance;
	diry = diry / distance;
	pos.x = pos.x + (dirx * speed * delta);
	pos.y = pos.y + (diry * speed * delta);
	this->shape.setPosition(pos.x, pos.y);
}
void enemy::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

void enemy::takedamage(int damage)
{
	this->health = std::max(0, this->health - damage);
	this->shape.setRadius(this->shape.getRadius() - 5);
	int newradius = this->shape.getRadius();
	this->shape.setOrigin(sf::Vector2f(newradius, newradius));
	this->speed += 50;
	if(this->health <= 0)
	{
		sceneManager::getInstance()->toremove.push_back(this);
		sceneManager::getInstance()->toremovephysicsobjects.push_back(this);
	}
}