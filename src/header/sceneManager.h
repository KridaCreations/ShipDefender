#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stdlib.h>
#include "grasspatch.h"
#include "nodecounter.h"
#include "nodecounter.h"
#include "node.h"
#include "gun.h"
#include "bullet.h"
#include "enemySpawner.h"
#include "enemy.h"
#include "mainscreen.h"
#include "scoremonitor.h"
#include "endscreen.h"


class sceneManager
{

private:
	static sceneManager* instancePtr;

public:
	std::unordered_set<node*>objects;//currobjects
	std::vector<node*>toadd; // objects which will be added 
	std::vector<node*>toremove; // objects which will be removed 
	std::unordered_set<node*>physicsobjects;
	std::vector<node*>toaddphysicsobjects;
	std::vector<node*>toremovephysicsobjects;
	nodecounter ncount; //node counter for generating the unique nodeids
	sf::Clock gameClock;//declaring game timer
	sf::RenderWindow* window = NULL;
	sf::Event* latestevent = NULL;
	grasspatch* ship = NULL;
	enemySpawner* enemyspawner = NULL;
	scoremonitor* scorecounter;
	


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

	void removescene();
	void startgame();
	void endgame();
	void showentryscreen();
	void showgameoverscreen(int score);
	sceneManager(const sceneManager& obj) = delete;



};

