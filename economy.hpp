#pragma once
#include <SFML/Graphics.hpp>
#include "comchan.hpp"

class Economy {
	Comchan &comchan;
	char selection = (char) 0;
	bool enterN = false, hasPer = false;
	const double posDeviation = 150;

	sf::Text
	input, price, amount,
	yeastP_, sucroseP_, juiceP_, waterP_,
	yeastMass_, sucroseMass_, juiceLitre_, waterLitre_, yeastPL_, atomicM_, hydrogenM_, carbonM_, oxygenM_,
	densities, monosaccharidegL_, disaccharidegL_, carbondioxidegL_, ethanolgL_, watergL_,
	enthalpyOfCombustion, ethanolEoC_, sucroseEoC_,
	informa;

	std::string
	yeast_0 = "Yeast: ", sucrose_0 = "Disaccharide: ", juice_0 = "Juice: ", water_0 = "Water: ", yeastPL_0 = "YPL: ";

	sf::Texture BGET, BET;
	sf::Sprite BGES, BES;

	sf::RenderWindow &window;
	sf::Font &font;

public:

	Economy(sf::RenderWindow &window, sf::Font &font, Comchan &comchan);
	void compute2();
	int enter(sf::RectangleShape &backGround);
	double molarMass(int,int,int);
};
