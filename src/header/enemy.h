#pragma once
#include "sceneManager.h"
class enemy : public node
{
public:
	sf::CircleShape shape;
	int health;
	int MAX_HEALTH;
	sf::Vector2f target;
	double speed;
	//(posx, posy, radius of enemy, target, color)
	enemy(double x, double y, int length,double speed,sf::Vector2f target, sf::Color color = sf::Color(50,58,168));

	void draw(sf::RenderWindow& window);
	void process(double delta);

	void takedamage(int damage);

	enemy() = delete;
};
