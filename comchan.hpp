#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
struct Comchan {

	std::string instream;
	double yeastPG, sucrosePG, juicePL, waterPL, yeastPL; //Needs to be exported to recipe for calculation.
	double hydrogenM, carbonM, oxygenM;
	double carbondioxideM, ethanolM, waterM,
				monosaccharideM, disaccharideM;
	double monosaccharidegL, disaccharidegL, carbondioxidegL, ethanolgL, watergL;
	double yeastP, sucroseP, juiceP, waterP,
			yeastMass, sucroseMass, juiceLitre, waterLitre;

	double totalVolume, totalDiSugarPerLitre, juiceVolume, juiceMonoSugarPerLitre, juiceDiSugarPerLitre, timeSpan;

	double ethanolEoC, sucroseEoC;
	double enthalpyC;
	double startMass, finalMass, volumeB;

	std::string name;
	int lastLoaded;
	int currentElement;

	std::vector<sf::Text> list, timeList;
	std::vector<double> timeTable;

	double volumeToAdd;
};

