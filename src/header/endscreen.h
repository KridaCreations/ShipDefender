#pragma once
#include "sceneManager.h"

class endscreen : public node
{
public:
	endscreen(int score,std::string fontpath);

	sf::Font basicfont;
	sf::Text scoretext;
	sf::Text instructiontext;

	void draw(sf::RenderWindow& window);
	void process(double delta);

	endscreen() = delete;
};

