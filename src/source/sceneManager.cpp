#include "../header/sceneManager.h"


void sceneManager::removescene()
{
	for (const auto& it : this->objects)
	{
		this->toremove.push_back(it);
	}

	for (auto& it : this->physicsobjects)
	{
		this->toremovephysicsobjects.push_back(it);
	}
	this->toadd.clear();
	this->toaddphysicsobjects.clear();
}


void sceneManager::startgame()
{
	int width = 800, height = 800;
	grasspatch* ground = new grasspatch((width / 2.0) - 150, (height / 2.0) - 150, 150, sf::Color(21, 124, 209)); //adding grasspatch
	this->toadd.push_back(ground);
	this->ship = ground;
	gun *machinegun = new gun((width / 2.0), (height / 2.0), 50, 10);
	this->toadd.push_back(machinegun);

	//adding the enemySpawner
	enemySpawner* enemynode = new enemySpawner(400);
	this->toadd.push_back(enemynode);
	this->enemyspawner = enemynode;

	//adding the score counter
	scoremonitor* newscorecounter = new scoremonitor("BebasNeue-Regular.ttf");
	this->scorecounter = newscorecounter;
	this->toadd.push_back(newscorecounter);

}

void sceneManager::endgame()
{

}


void sceneManager::showentryscreen()
{
	mainscreen* entry = new mainscreen("BebasNeue-Regular.ttf");
	this->toadd.push_back(entry);
}

void sceneManager::showgameoverscreen(int score)
{
	endscreen* end = new endscreen(score,"BebasNeue-Regular.ttf");
	this->toadd.push_back(end);

}