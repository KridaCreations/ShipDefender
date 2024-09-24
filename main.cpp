#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include "node.h"
#include "grasspatch.h"
#include "nodecounter.h"
#include "sceneManager.h"
using namespace std;

sceneManager* sceneManager::instancePtr = nullptr;

int main()
{
	double width = 1500, height = 800;
	sf::RenderWindow window(sf::VideoMode(1500, 800), "My window", sf::Style::Default);
	
	sceneManager* scene = new sceneManager();

	grasspatch ground(width/2.0, height/2.0, 12); //adding grasspatch
	(scene->objects).insert(&ground);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();



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
			cout << endl;

			window.display();	
		}

	}

	return 0;
}