#include "header/sceneManager.h"


using namespace std;

sceneManager* sceneManager::instancePtr = nullptr;

int main()
{
	double width = 800, height = 800;
	sceneManager* scene = sceneManager::getInstance();//new sceneManager();
	sf::RenderWindow window(sf::VideoMode(width, height), "My window", sf::Style::Default);
	scene->window = &window;

	grasspatch ground((width / 2.0)-150, (height / 2.0)-150, 150); //adding grasspatch
	(scene->objects).insert(&ground);
	scene->grasspatch = &ground;
	gun machinegun((width / 2.0), (height / 2.0), 50,10);
	(scene->objects).insert(&machinegun);

	//adding the enemySpawner
	enemySpawner enemynode(400);
	(scene->objects).insert(&enemynode);

	while (window.isOpen())
	{

		//adding new nodes to the drawable nodes list
		for (auto it : (scene->toadd))
		{
			scene->objects.insert(it);
		}
		scene->toadd.clear();
		//removing nodes to be removed from queue;
		for (auto it : (scene->toremove))
		{
			scene->objects.erase(it);
			delete it;
		}
		scene->toremove.clear();
		
		for (auto it : (scene->toaddphysicsobjects))
		{
			scene->physicsobjects.insert(it);
		}
		scene->toaddphysicsobjects.clear();
		
		for (auto it : (scene->toremovephysicsobjects))
		{
			scene->physicsobjects.erase(it);
		}
		scene->toremovephysicsobjects.clear();

		
		
		//getting event
		sf::Event event;
		scene->latestevent = NULL;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			scene->latestevent = &event;

		}


		//calling the process functions
		sf::Time deltatime = scene->gameClock.getElapsedTime(); //deltatime
		double usec = deltatime.asMicroseconds();
		scene->gameClock.restart(); //timer restart
		for (auto& it : scene->objects)
		{
			it->process(usec/(1000000.000));
		}


		//drawing all the objects;
		window.clear(sf::Color::Magenta);
		for (auto& it : scene->objects)
		{
			it->draw(window);
		}
		window.display();	

	}

	return 0;
}