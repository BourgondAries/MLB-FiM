#pragma once
#include <SFML/Graphics.hpp>

class Load {
	std::vector<sf::Text> timeList;
	sf::Text notification;
	sf::RenderTexture overlay1, overlay2;
	sf::Sprite overlayS1, overlayS2;
	sf::RectangleShape marker, toppy;
	std::vector<double> timeTable;
	unsigned int currentElement = 0;
	unsigned int selection = 1;
public:

	void createList();
	void updateTimer();
	Load();
	int enter();
};
