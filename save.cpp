#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "save.hpp"
#include <fstream>
#include <cstdio>
#include <string>
#include <ctime>

extern std::fstream loadList;
extern double totalVolume, totalDiSugarPerLitre, juiceVolume, juiceMonoSugarPerLitre, juiceDiSugarPerLitre, timeSpan;
extern double startMass, finalMass, volumeB;
extern double yeastP, sucroseP, juiceP, waterP, yeastPL,
		yeastMass, sucroseMass, juiceLitre, waterLitre;
extern double monosaccharidegL, disaccharidegL, carbondioxidegL, ethanolgL, watergL;
extern double hydrogenM, carbonM, oxygenM;
std::string name;
extern int lastLoaded;
extern sf::Sprite screenS;
extern double ethanolEoC, sucroseEoC;

std::string n2s(double);
void createList();

extern std::vector<sf::Text> list;

Save::Save(sf::RenderWindow &window, const sf::Font &font)
{
	teller.setFont(font); nameT.setFont(font);
	teller.setCharacterSize(10); nameT.setCharacterSize(10);
	teller.setString("Please specify a project name:");
	teller.setPosition(800 / 2 - (int)teller.getGlobalBounds().width / 2, (int)600 / 2 - 50); nameT.setPosition(800 / 2 - (int)teller.getGlobalBounds().width / 2, (int)600 / 2 - 32);

	boxr.setSize(sf::Vector2f(200,10)); boxr.setPosition(50,51); boxr.setFillColor(sf::Color(127,127,127,220)); boxr.setOutlineColor(sf::Color(0,0,0,66)); boxr.setOutlineThickness(1);
	box.create(300,100);
	box.clear(sf::Color(127,127,127,200));
	box.draw(boxr);
	box.display();
	boxS.setTexture(box.getTexture());
	boxS.setPosition(250,220);
}

int Save::enter()
{
	if (window.waitEvent(event)); ///In order to skip the "s" shortcut from being added to the writing que.
	begin:
	if (window.waitEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				return 1;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						tooMany = false;
						error = false;
						justSaved = false;
						return 0;
					case sf::Keyboard::Return:
					if (name.size() > 0)
					{
						if (list.size() < 40)
						{
							///Entry in the main save (save overview)
							for (unsigned int i = 1; i < list.size() - 1; i++) //Finder
							{
								std::string temporary = static_cast<std::string>(list[i].getString());
								temporary.erase(temporary.begin());
								if (temporary == std::string(name))
								{
									alreadyThere = true;
									lastLoaded = i;
									goto alreadyContained;
								}
							}
							actual.open("loadList.txt", std::ios::out | std::ios::app);
							actual << name << "," << (int)(timeSpan + (int)std::time(NULL)) << "\n";
							actual.close();
							lastLoaded = list.size() - 1;
							createList();
							alreadyThere = false;
							alreadyContained: //Skips the above algorithm for saving.
							//Now the file will be saved, an entry will be added to the global load file.
							///Saving
							std::string tempName = std::string("save/" + name + ".txt");
							actual.open(tempName.c_str(), std::ios::out);
							actual << "TV: " << n2s(totalVolume) << "\n"
							<< "DPL: " << n2s(totalDiSugarPerLitre) << "\n"
							<< "JV: " << n2s(juiceVolume) << "\n"
							<< "JMPL: " << n2s(juiceMonoSugarPerLitre) << "\n"
							<< "JDPL: " << n2s(juiceDiSugarPerLitre) << "\n"
							<< "SM: " << n2s(startMass) << "\n"
							<< "FM: " << n2s(finalMass) << "\n"
							<< "FV: " << n2s(volumeB) << "\n"
							<< "YP: " << n2s(yeastP) << "\n"
							<< "SP: " << n2s(sucroseP) << "\n"
							<< "JP: " << n2s(juiceP) << "\n"
							<< "WP: " << n2s(waterP) << "\n"
							<< "YM: " << n2s(yeastMass) << "\n"
							<< "SM: " << n2s(sucroseMass) << "\n"
							<< "JL: " << n2s(juiceLitre) << "\n"
							<< "WL: " << n2s(waterLitre) << "\n"
							<< "TS: " << ((unsigned long long int)timeSpan) << "\n"
							<< "MSGL: " << n2s(monosaccharidegL) << "\n"
							<< "DSGL: " << n2s(disaccharidegL) << "\n"
							<< "CDGL: " << n2s(carbondioxidegL) << "\n"
							<< "EOGL: " << n2s(ethanolgL) << "\n"
							<< "WRGL: " << n2s(watergL) << "\n"
							<< "HM: " << n2s(hydrogenM) << "\n"
							<< "CM: " << n2s(carbonM) << "\n"
							<< "OM: " << n2s(oxygenM) << "\n"
							<< "YPL: " << n2s(yeastPL) << "\n"
							<< "EEOC: " << n2s(ethanolEoC) << "\n"
							<< "SEOC: " << n2s(sucroseEoC);
							actual.close();
							justSaved = true;
						}
						else
						{
							error = true;
							tooMany = true;
						}
					}
					else
					{
						error = true;
						tooMany = false;
					}
						break;
					case sf::Keyboard::BackSpace:
						if (name.size() > 0)
							name.erase(name.size() - 1);
						justSaved = false;
						error = false;
						tooMany = false;
						break;
					case sf::Keyboard::Space:
						if (name.size() < 28)
							name.push_back((char) 32); //32 is a space
						justSaved = false;
						error = false;
						tooMany = false;
						break;
					default: break;
				}
				break;
			case sf::Event::TextEntered:
				if (name.size() < 28 && ((event.text.unicode >= 97 && event.text.unicode <= 122) || (event.text.unicode >= 65 && event.text.unicode <= 90) || (event.text.unicode >= 48 && event.text.unicode <= 57)))
				{
					name.push_back(static_cast<char>(event.text.unicode));
					justSaved = false;
					error = false;
					tooMany = false;
				}
				break;
			default: break;
		}
		if (error)
		{
			nameT.setColor(sf::Color::Red);
			if (tooMany)
				nameT.setString(name + "_" + "\n\n\t-> Too many entries");
			else
				nameT.setString(name + "_" + "\n\n\t-> Specify a title");
		}
		else if (justSaved && alreadyThere)
		{
			nameT.setColor(sf::Color::Green);
			nameT.setString(name + std::string("_") + std::string("\n\n\t-> Save Successful\n\t-> Overwritten"));
		}
		else if (justSaved)
		{
			nameT.setColor(sf::Color::Green);
			nameT.setString(name + std::string("_") + std::string("\n\n\t-> Save Successful"));
		}
		else
		{
			nameT.setColor(sf::Color::Yellow);
			nameT.setString(name + std::string("_"));
		}
	}
	window.clear();
	window.draw(screenS);
	window.draw(boxS);
	window.draw(nameT);
	window.draw(teller);
	window.display();
	goto begin;
	return 1;
}
