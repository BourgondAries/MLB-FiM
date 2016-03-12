#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include <iostream>
#include "save.hpp"
#include <fstream>
#include <cstdio>
#include <string>
#include <ctime>

std::string n2s(double);

Save::Save(sf::RenderWindow &window, sf::Font &font, Comchan &comchan)
:
	window(window),
	font(font),
	comchan(comchan)
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

void Save::createList() {
	auto &list = comchan.list;
	auto &timeTable = comchan.timeTable;
	auto &timeList = comchan.timeList;
	auto &currentElement = comchan.currentElement;
	auto &lastLoaded = comchan.lastLoaded;
	std::fstream loadList;
	loadList.open("loadList.txt");
	char temp;
	bool commaFound = false;
	std::string information = " ", timeInfo;
	list.clear(); timeList.clear(); timeTable.clear();
	list.push_back(sf::Text(" Project Title", font, 10));
	timeList.push_back(sf::Text("Time Left", font, 10));
	while (loadList.good())
	{
		temp = loadList.get();
		if (temp == 44)
		{
			commaFound = true;
		}
		else if (temp != 10)
		{
			if (commaFound)
			{
				timeInfo.push_back(temp);
			}
			else
				information.push_back(temp);
		}
		else
		{
			//Push on the stack
			list.push_back(sf::Text(information, font, 10));
			//converting to time - left:
			timeTable.push_back(std::atof(timeInfo.c_str()));
			int timez = std::atof(timeInfo.c_str()) - (int)std::time(NULL);
			unsigned int weeks = ((int)timez) / 604800; unsigned int days = ((int)timez - weeks * 604800) / 86400; unsigned int hours = ((int)timez - weeks * 604800 - days * 86400) / 3600; unsigned int minutes = ((int)timez - weeks * 604800 - days * 86400 - hours * 3600) / 60; unsigned int seconds = ((int)timez - weeks * 604800 - days * 86400 - hours * 3600 - minutes * 60);
			std::string timeLeft = n2s(weeks) + " W " + n2s(days) + " d " + n2s(hours) + " h " + n2s(minutes) + " m " + n2s(seconds) + " s";

			timeList.push_back(sf::Text(timeLeft, font, 10));
			list[currentElement].setPosition(0, currentElement * 10);
			timeList[currentElement].setPosition(0, currentElement * 10);
			currentElement++;
			information.clear(); information.push_back(' ');
			timeInfo.clear();
			commaFound = false;
		}
	}
	if (information.size() >= 1)
		information.erase(information.size() - 1);
	if (timeInfo.size() >= 1)
		timeInfo.erase(timeInfo.size() - 1);
	list.push_back(sf::Text(information, font, 10));
	timeList.push_back(sf::Text(timeInfo, font, 10));
	list[currentElement].setPosition(0, currentElement * 10);
	timeList[currentElement].setPosition(0, currentElement * 10);
	information.clear();
	timeInfo.clear();
	currentElement = 0;
	if (lastLoaded >= 1)
		list[lastLoaded].setColor(sf::Color::Cyan);
}

int Save::enter(sf::Sprite &screenS)
{
	createList();
	auto &startMass = comchan.startMass;
	auto &finalMass = comchan.finalMass;
	auto &volumeB = comchan.volumeB;
	auto &volumeToAdd = comchan.volumeToAdd;
	auto &totalVolume = comchan.totalVolume;
	auto &juiceVolume = comchan.juiceVolume;
	auto &juiceDiSugarPerLitre = comchan.juiceDiSugarPerLitre;
	auto &juiceMonoSugarPerLitre = comchan.juiceMonoSugarPerLitre;
	auto &disaccharideM = comchan.disaccharideM;
	auto &monosaccharideM = comchan.monosaccharideM;
	auto &monosaccharidegL = comchan.monosaccharidegL;
	auto &disaccharidegL = comchan.disaccharidegL;
	auto &carbondioxideM = comchan.carbondioxideM;
	auto &carbondioxidegL = comchan.carbondioxidegL;
	auto &ethanolM = comchan.ethanolM;
	auto &ethanolgL = comchan.ethanolgL;
	auto &waterM = comchan.waterM;
	auto &watergL = comchan.watergL;
	auto &enthalpyC = comchan.enthalpyC;
	auto &timeSpan = comchan.timeSpan;
	auto &yeastPL = comchan.yeastPL;
	auto &yeastPG = comchan.yeastPG;
	auto &sucrosePG = comchan.sucrosePG;
	auto &juicePL = comchan.juicePL;
	auto &waterPL = comchan.waterPL;
	auto &totalDiSugarPerLitre = comchan.totalDiSugarPerLitre;
	auto &instream = comchan.instream;
	auto &name = comchan.name;
	auto &lastLoaded = comchan.lastLoaded;
	auto &sucroseEoC = comchan.sucroseEoC;
	auto &ethanolEoC = comchan.ethanolEoC;
	auto &oxygenM = comchan.oxygenM;
	auto &carbonM = comchan.carbonM;
	auto &hydrogenM = comchan.hydrogenM;
	auto &waterLitre = comchan.waterLitre;
	auto &juiceLitre = comchan.juiceLitre;
	auto &sucroseMass = comchan.sucroseMass;
	auto &yeastMass = comchan.yeastMass;
	auto &waterP = comchan.waterP;
	auto &juiceP = comchan.juiceP;
	auto &sucroseP = comchan.sucroseP;
	auto &yeastP = comchan.yeastP;
	auto &list = comchan.list;
	auto &timeTable = comchan.timeTable;
	auto &timeList = comchan.timeList;

	sf::Event event;
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
								if (list.size() == 0)
									break;
								std::string temporary = list[i].getString();
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
							// createList();
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
