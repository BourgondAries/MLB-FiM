#pragma once
#include <SFML/Graphics.hpp>
#include "comchan.hpp"

class Product {
	char selection = (char) 0;
	const double posDeviation = 180;
	bool enterN = false, hasPer = false;

	double
	carbonDMol, carbonDMass, carbonDVolume,
	ethanolMol, ethanolMass, ethanolVolume,
	ABV, EPL;

	sf::Text
	input, mol, mass, volume, misc,
	startMass_, finalMass_, volumeB_,
	carbonDMol_, carbonDMass_, carbonDVolume_,
	ethanolMol_, ethanolMass_, ethanolVolume_,
	ABV_, EPL_,

	info;

	std::string
	startMass_0 = "Start Mass: ", finalMass_0 = "Final Mass: ", volumeB_0 = "Volume: ",
	carbonD_0 = "Carbondioxide: ",
	ethanol_0 = "Ethanol: ",
	ABV_0 = "ABV: ";

	sf::Texture backGroundT, bannerT;
	sf::Sprite backGroundS, bannerS;
	sf::RenderWindow &window;
	sf::Font &font;
	Comchan &comchan;
	sf::RectangleShape &backGround;
public:
	Product(sf::RenderWindow &window, sf::Font &font, Comchan &comchan, sf::RectangleShape &backGround);
	void calculate();
	int enter();
};
