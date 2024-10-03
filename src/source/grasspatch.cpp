#include "../header/sceneManager.h"




grasspatch::grasspatch(double x, double y, double length, sf::Color color):node(x, y)
{
	this->shape.setPosition(x, y);
	this->shape.setRadius(length);
	this->shape.setFillColor(color);
	this->health = this->MAX_HEALTH;
}

void grasspatch::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);

	//drawing the health bar
	//drawing background..........
	sf::RectangleShape background; 
	sf::Vector2f pos = this->shape.getPosition();
	background.setPosition(pos.x, pos.y-30);
	background.setSize(sf::Vector2f(300, 20));
	background.setFillColor(sf::Color(245, 5, 5));

	//drawing the frontgound
	sf::RectangleShape frontground;
	double len = ((float)this->health / (float)this->MAX_HEALTH) * (300.00);
	frontground.setPosition(pos.x, pos.y - 30);
	frontground.setSize(sf::Vector2f(len, 20));
	frontground.setFillColor(sf::Color(241, 245, 5));

	window.draw(background);
	window.draw(frontground);

}

void grasspatch::process(double delta)
{
	
}

void grasspatch::takedamage(int damage)
{
	this->health = std::max(0, this->health - damage);

	if (this->health <= 0)
	{
		//code for ending the game here
	}
}

