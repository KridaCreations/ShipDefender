#include "../header/sceneManager.h"

endscreen::endscreen(int score, std::string fontpath):node(0,0)
{
	if (!this->basicfont.loadFromFile(fontpath))
	{
		std::cout << "font coudn't be loaded" << std::endl;
	}
	this->instructiontext.setFont(this->basicfont);
	this->scoretext.setFont(this->basicfont);
	this->instructiontext.setString("Press \"LEFT\" mouse button to start game");
	this->instructiontext.setCharacterSize(45);
	this->instructiontext.setFillColor(sf::Color::White);
	this->instructiontext.setStyle(sf::Text::Bold);
	this->instructiontext.setPosition(80, 300);

	this->scoretext.setString("Your score " + std::to_string(score));
	this->scoretext.setCharacterSize(45);
	this->scoretext.setFillColor(sf::Color::White);
	this->scoretext.setStyle(sf::Text::Bold);
	this->scoretext.setPosition(150, 240);
}

void endscreen::draw(sf::RenderWindow& window)
{
	window.draw(this->scoretext);
	window.draw(this->instructiontext);
}

void endscreen::process(double delta)
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