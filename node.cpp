#include "node.h"
#include <iostream>
#include "sceneManager.h"
node::node(double x, double y)
{
	sceneManager* scene = sceneManager::getInstance();
	this->nodeid = scene->ncount.getNewId();
	this->x = x;
	this->y = y;
}
void node::ready()
{

}
void node::process(double delta)
{

}
void node::draw(sf::RenderWindow &window)
{
	
}