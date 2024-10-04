#include "../header/sceneManager.h"

scoremonitor::scoremonitor(std::string fontpath):node(0,0)
{
	if (!(this->scorefont.loadFromFile(fontpath)))
	{
		std::cout << "font not loaded " << std::endl;
	}
	this->scoretext.setFont(this->scorefont);
	this->scoretext.setString(std::to_string(this->currentscore));
	this->scoretext.setCharacterSize(45);
	this->scoretext.setFillColor(sf::Color::White);
}

void scoremonitor::draw(sf::RenderWindow& window)
{
	window.draw(this->scoretext);
}

void scoremonitor::process(double delta)
{
	this->scoretext.setString(std::to_string(this->currentscore));
}
