#include "../header/sceneManager.h"

class mainscreen : public node
{
public:
	mainscreen(std::string fontpath);

	sf::Font basicfont;
	sf::Text text;

	void draw(sf::RenderWindow& window);
	void process(double delta);

	mainscreen() = delete;
};