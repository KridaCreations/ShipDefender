#include "header/sceneManager.h"


using namespace std;

sceneManager* sceneManager::instancePtr = nullptr;

int main()
{
	double width = 800, height = 800;
	sceneManager* scene = sceneManager::getInstance();
	sf::RenderWindow window(sf::VideoMode(width, height), "My window", sf::Style::Titlebar| sf::Style::Close);
	scene->window = &window;

	scene->showentryscreen();

	while (window.isOpen())
	{

		//removing nodes to be removed from queue;
		for (auto& it : (scene->toremovephysicsobjects))
		{
			if ((it != NULL) && ((scene->physicsobjects.find(it)) != (scene->physicsobjects.end())))
			{
				scene->physicsobjects.erase(it);
			}
		}
		scene->toremovephysicsobjects.clear();
		

		for (auto& it : (scene->toremove))
		{
			if ((it != NULL) && ((scene->objects.find(it)) != (scene->objects.end())))
			{
				scene->objects.erase(it);
				delete it;
			}
		}
		scene->toremove.clear();
		

		//adding new nodes to the drawable nodes list
		for (auto it : (scene->toadd))
		{
			scene->objects.insert(it);
		}
		scene->toadd.clear();

		for (auto it : (scene->toaddphysicsobjects))
		{
			scene->physicsobjects.insert(it);
		}
		scene->toaddphysicsobjects.clear();
		

		
		
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
		window.clear(sf::Color::Black);
		for (auto& it : scene->objects)
		{
			it->draw(window);
		}
		window.display();	

	}

	return 0;
}