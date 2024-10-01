#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
//#include "sceneManager.h"
class node
{
public:
	double x = 0, y = 0;
	int nodeid;
	
	//constructors
	node(double x, double y);


	//virtual functions
	virtual void ready();
	virtual void process(double delta = 0.0);
	virtual void draw(sf::RenderWindow &window);

	//deleted functions
	node() = delete;
};

