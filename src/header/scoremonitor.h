#pragma once
#include "sceneManager.h"


class scoremonitor : public node
{
public:
	int currentscore = 0;
	sf::Font scorefont;
	sf::Text scoretext;

	scoremonitor(std::string fontpath);
	void draw(sf::RenderWindow& );
	void process(double delta);

	scoremonitor() = delete;
};

