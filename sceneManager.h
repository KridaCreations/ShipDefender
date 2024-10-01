#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stdlib.h>
#include "grasspatch.h"
#include "nodecounter.h"
#include "nodecounter.h"
#include "node.h"

class sceneManager
{

private:
	static sceneManager* instancePtr;

public:
	std::unordered_set<node*>objects;//currobjects
	std::vector<node*>toadd; // objects which will be added 
	std::vector<node*>toremove; // objects which will be removed 
	nodecounter ncount; //node counter for generating the unique nodeids
	sf::Clock gameClock;//declaring game timer
	sf::RenderWindow* window;
private:
	sceneManager() {

	}
	//static mutex mtx; //maybe for future use

public:
	static sceneManager* getInstance() {
		if (instancePtr == nullptr) {
			//lock_guard<mutex> lock(mtx); //maybe for future use
			if (instancePtr == nullptr) {
				instancePtr = new sceneManager();
			}
		}
		return instancePtr;
	}


	sceneManager(const sceneManager& obj) = delete;


};

