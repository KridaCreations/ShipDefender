#include "../header/sceneManager.h"



gun::gun(double x, double y, double length, double width, sf::Color color) :node(x, y)
{
	this->shape.setOrigin(0,width/2);
	this->shape.setPosition(x, y);
	this->shape.setSize(sf::Vector2f(length,width));
	this->shape.setFillColor(color);
	
	if (this->buffer.loadFromFile("gunsound1.wav"))
	{
		std::cout << "setting the buffer " << std::endl;
		this->gunsound.setBuffer(this->buffer);
	}
	
}

void gun::draw(sf::RenderWindow& window)
{
	window.draw(this->shape);
}

void gun::process(double delta)
{
	sceneManager* scene = sceneManager::getInstance();
	sf::Vector2i mlocalpos = sf::Mouse::getPosition(*(scene->window));
	
	lookat(mlocalpos.x, mlocalpos.y);
	
	if (scene->latestevent != NULL)
	{
		if ((scene->latestevent->type) == sf::Event::MouseButtonPressed)
		{
			if (scene->latestevent->mouseButton.button == sf::Mouse::Left)
			{
				double relx = scene->latestevent->mouseButton.x - this->shape.getPosition().x;
				double rely = scene->latestevent->mouseButton.y - this->shape.getPosition().y;
				double disfromcenter = std::sqrt((relx*relx) + (rely*rely));
				double bullposx = ((relx / disfromcenter) * this->shape.getSize().x) + this->shape.getPosition().x;
				double bullposy = ((rely / disfromcenter) * this->shape.getSize().x) + this->shape.getPosition().y;
				sf::Vector2f bulldirec(relx,rely);
				double speed = 1000;
				bullet* newbullet = new bullet(bullposx, bullposy, bulldirec, speed);
				scene->toadd.push_back(newbullet);
				
				//playing sound
				this->gunsound.play();
			}

		}
	}

}

void gun::lookat(double x, double y)
{
	double relx = x - this->shape.getPosition().x;
	double rely = y - this->shape.getPosition().y;

	double dotproduct = (relx * 1) + (rely * 0);
	double length = (relx * relx) + (rely * rely);

	length = std::sqrt(length);
	dotproduct = dotproduct / (length);
	double angle = acos(dotproduct);
	double indegreeangle = (angle * (180.0)) / 3.14;
	if (rely < 0)
	{
		indegreeangle = 360 - indegreeangle;
	}
	this->shape.setRotation(indegreeangle);
}


