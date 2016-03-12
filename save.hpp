#pragma once
#include <fstream>
#include "comchan.hpp"
#include <SFML/Graphics.hpp>

class Save {
	std::fstream actual;
	bool justSaved = false;
	bool alreadyThere = false;
	bool error = false;
	bool tooMany = false;
	sf::Text teller, nameT;
	sf::RectangleShape boxr;
	sf::RenderTexture box;
	sf::Sprite boxS;
	sf::RenderWindow &window;
	sf::Font &font;
	std::fstream loadList;
	Comchan &comchan;
public:

	Save(sf::RenderWindow &window, sf::Font &font, Comchan &comchan);
	int enter(sf::Sprite &screenS);
	void createList();
};
