#include "sceneManager.h"
#include "gun.h"

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

	gun machinegun((width / 2.0), (height / 2.0), 50,10);
	(scene->objects).insert(&machinegun);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

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