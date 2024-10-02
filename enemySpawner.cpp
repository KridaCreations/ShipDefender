#include "sceneManager.h"

enemySpawner::enemySpawner(int length):node(10,10)
{
	this->length = length;
	this->Clock.restart();
}

void enemySpawner::process(double delta)
{
	if ((this->Clock.getElapsedTime().asSeconds() > 2))
	{
		sf::Vector2f pos = this->create_enemy_pos();
		std::cout << "new enemt pos " << pos.x << " " << pos.y << std::endl;
		node* newenemy = new enemy(pos.x,pos.y,50,10,sf::Vector2f(400,400));
		sceneManager::getInstance()->toadd.push_back(newenemy);
		sceneManager::getInstance()->toaddphysicsobjects.push_back(newenemy);
		this->Clock.restart();
	}
}

sf::Vector2f enemySpawner::create_enemy_pos()
{
	double x = (rand() % 10) - 5;
	double y = (rand() % 10) - 5;
	double currlen = std::sqrt((x * x) + (y * y));
	x = (x * (this->length)) / currlen;
	y = (y * (this->length)) / currlen;
	return sf::Vector2f(x+400.0, y+400.0);
}

void enemySpawner::draw()
{

}
