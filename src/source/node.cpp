
#include "../header/sceneManager.h"
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
node::~node()
{
	sceneManager::getInstance()->ncount.removeId(this->nodeid);
}