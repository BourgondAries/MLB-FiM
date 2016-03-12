#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "comchan.hpp"

class Load {
	std::vector<sf::Text> timeList;
	sf::Text notification;
	sf::RenderTexture overlay1, overlay2;
	sf::Sprite overlayS1, overlayS2;
	sf::RectangleShape marker, toppy;
	unsigned int currentElement = 0;
	unsigned int selection = 1;
	sf::RenderWindow &window;
	sf::Font &font;
	Comchan &comchan;
	std::fstream loadList;
public:

	void createList();
	void updateTimer();
	Load(sf::RenderWindow &window, sf::Font &font, Comchan &comchan);
	int enter(sf::Sprite &screenS);
};
