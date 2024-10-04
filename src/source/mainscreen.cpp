#include "../header/sceneManager.h"

mainscreen::mainscreen(std::string fontpath) :node(0, 0)
{
	if (!(this->basicfont.loadFromFile(fontpath)))
	{
		std::cout << "cant load font" << std::endl;
	}
	this->text.setFont(this->basicfont);
	this->text.setString("Press \"LEFT\" mouse button to start game");
	this->text.setCharacterSize(45);
	this->text.setFillColor(sf::Color::White);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(80, 300);
}

void mainscreen::process(double delta)
{
	sceneManager* scene = sceneManager::getInstance();
	if (scene->latestevent != NULL)
	{
		if ((scene->latestevent->type) == sf::Event::MouseButtonPressed)
		{
			if (scene->latestevent->mouseButton.button == sf::Mouse::Left)
			{
				scene->removescene();
				scene->startgame();
			}

		}
	}
}

void mainscreen::draw(sf::RenderWindow& window)
{
	window.draw(this->text);
}