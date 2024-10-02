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
		//std::cout << "deleting bullet id "<<this->nodeid<<" \n ";
		sceneManager::getInstance()->toremove.push_back(this);
	}


	//physics calculation
	for (auto& it : sceneManager::getInstance()->physicsobjects)
	{
		enemy* enem = dynamic_cast<enemy*>(it);
		sf::Vector2f enemypos = enem->shape.getPosition();
		sf::Vector2f pos = this->shape.getPosition();
		double disx = std::abs(enemypos.x - pos.x);
		double disy = std::abs(enemypos.y - pos.y);
		double distance = std::sqrt((disx * disx) + (disy * disy));
		int enemysize = enem->shape.getRadius();
		if (distance < enemysize)
		{
			enem->takedamage(10);
			sceneManager::getInstance()->toremove.push_back(this);
		}
	}
}

void bullet::lookat(double x, double y)
{

}