#pragma once
#include "sceneManager.h"
class enemySpawner: public node
{
public:
	int length;
	enemySpawner(int length);
	void process(double delta);
	void draw();
	sf::Clock Clock;
	sf::SoundBuffer enemyhitsoundbuffer;
	enemySpawner() = delete;
private:
	sf::Vector2f create_enemy_pos();

};

