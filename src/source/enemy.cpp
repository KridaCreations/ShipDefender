#include "../header/sceneManager.h"

enemy::enemy(double x, double y, int length,double speed,sf::Vector2f target, sf::Color color):node(x,y)
{
	this->shape.setOrigin((float)length, (float)length);
	this->shape.setPosition(x, y);
	this->speed = speed;
	this->MAX_HEALTH = length;
	this->health = this->MAX_HEALTH;
	this->target = target;
	this->shape.setRadius(length);
	this->shape.setOutlineThickness(2);
	this->hurtsound.setBuffer(sceneManager::getInstance()->enemyspawner->enemyhitsoundbuffer);
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


	//checking collision with grasspatch

	double disx = std::abs(pos.x - 400);
	double disy = std::abs(pos.y - 400);
	double length = std::sqrt((disx * disx) + (disy * disy));
	if (length < (this->shape.getRadius() + 150)) // 150 is radius of the grasspatch
	{
		sceneManager::getInstance()->ship->takedamage(this->health / 2);

		sceneManager::getInstance()->toremove.push_back(this);
		sceneManager::getInstance()->toremovephysicsobjects.push_back(this);
	}


}
void enemy::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);



	//drawing the health bar
	//drawing background..........

	int barlen = this->shape.getRadius() * 2;
	sf::RectangleShape background;
	sf::Vector2f pos = this->shape.getPosition();
	background.setPosition(pos.x - (this->shape.getRadius()), pos.y - (this->shape.getRadius()) - 15);
	background.setSize(sf::Vector2f(barlen, 10));
	background.setFillColor(sf::Color(245, 5, 5));

	//drawing the frontgound
	sf::RectangleShape frontground;
	double len = ((float)this->health / (float)this->MAX_HEALTH) * (barlen);
	frontground.setPosition(pos.x - (this->shape.getRadius()), pos.y - (this->shape.getRadius()) - 15);
	frontground.setSize(sf::Vector2f(len, 10));
	frontground.setFillColor(sf::Color(241, 245, 5));

	window.draw(background);
	window.draw(frontground);
}

void enemy::takedamage(int damage)
{
	this->health = std::max(0, this->health - damage);
	this->shape.setRadius(this->shape.getRadius() - 5);
	int newradius = this->shape.getRadius();
	this->shape.setOrigin(sf::Vector2f(newradius, newradius));
	this->speed += 50;
	//this->hurtsound.setPlayingOffset(sf::seconds(0.2f));
	//this->hurtsound.play();

	if(this->health <= 0)
	{
		sceneManager::getInstance()->scorecounter->currentscore += 1;
		sceneManager::getInstance()->toremove.push_back(this);
		sceneManager::getInstance()->toremovephysicsobjects.push_back(this);
	}
}