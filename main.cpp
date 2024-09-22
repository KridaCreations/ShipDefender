#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "grasspatch.h"
#include "nodecounter.h"
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default);
	vector<node*>objects;

	nodecounter ncount;
	grasspatch ground(ncount.getNewId(), 0, 0, 12);
	objects.push_back(&ground);
	cout << objects.back()->x<<" "<<objects.back()->nodeid<< endl;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Magenta);

		window.display();
	}

	return 0;
}