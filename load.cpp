#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include "load.hpp"
#include <fstream>
#include <ctime>
#include <utility>
#include <cstdlib>
#include <string>
#include <cstdio>

std::string n2s(double);

void Load::updateTimer()
{
	auto &list = comchan.list;
	auto &timeTable = comchan.timeTable;
	auto &timeList = comchan.timeList;
		unsigned int currentTime = (unsigned int) std::time(NULL);
		for (unsigned int i = 1; i <= timeTable.size(); i++)
		{
			int timez = (int)timeTable[i-1] - (int)currentTime;
			if (timez <= 0)
			{
				timeList[i].setColor(sf::Color::Red);
				timeList[i].setString("Finished!");
				continue;
			}
			unsigned int weeks = ((int)timez) / 604800; unsigned int days = ((int)timez - weeks * 604800) / 86400; unsigned int hours = ((int)timez - weeks * 604800 - days * 86400) / 3600; unsigned int minutes = ((int)timez - weeks * 604800 - days * 86400 - hours * 3600) / 60; unsigned int seconds = ((int)timez - weeks * 604800 - days * 86400 - hours * 3600 - minutes * 60);
			std::string timeLeft = n2s(weeks) + " W " + n2s(days) + " d " + n2s(hours) + " h " + n2s(minutes) + " m " + n2s(seconds) + " s";
			timeList[i].setString(timeLeft);
		}
}

void Load::createList() {
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

Load::Load(sf::RenderWindow &window, sf::Font &font, Comchan &comchan)
:
	window(window),
	font(font),
	comchan(comchan)
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


		overlay1.create(300,450); overlay2.create(300,450);
		overlay1.clear(sf::Color(0,127,0,200)); overlay2.clear(sf::Color(0,127,0,200));
		overlay1.display(); overlay2.display();
		overlayS1.setTexture(overlay1.getTexture()); overlayS2.setTexture(overlay2.getTexture());
		overlayS1.setPosition(100,75);overlayS2.setPosition(400,75);
		marker.setSize(sf::Vector2f(600,10)); toppy.setSize(sf::Vector2f(600,1));
		marker.setFillColor(sf::Color(255,255,0,127)); toppy.setFillColor(sf::Color(0,70,0));
		marker.setPosition(100,87); toppy.setPosition(100,87);

		notification.setFont(font); notification.setCharacterSize(10); notification.setPosition(100,510); notification.setString("         Arrows to navigate\tEnter/return to load\tDelete to delete\tEscape to return"); notification.setColor(sf::Color(0,0,127,255));


///Load Standard stuff
		std::fstream actual("standard.txt");
		unsigned int termCounter = 0;
		std::string numberHolder;
		while (actual.good())
		{
			char temp = actual.get();
			if ((temp >= 48 && temp <= 57) || temp == 46)
				numberHolder.push_back(temp);
			else if (temp == 10)
			{
				switch (termCounter)
				{
					case 0: totalVolume = std::atof(numberHolder.c_str()); break;
					case 1: totalDiSugarPerLitre = std::atof(numberHolder.c_str()); break;
					case 2: juiceVolume = std::atof(numberHolder.c_str()); break;
					case 3: juiceMonoSugarPerLitre = std::atof(numberHolder.c_str()); break;
					case 4: juiceDiSugarPerLitre = std::atof(numberHolder.c_str()); break;
					case 5: startMass = std::atof(numberHolder.c_str()); break;
					case 6: finalMass = std::atof(numberHolder.c_str()); break;
					case 7: volumeB = std::atof(numberHolder.c_str()); break;
					case 8: yeastP = std::atof(numberHolder.c_str()); break;
					case 9: sucroseP = std::atof(numberHolder.c_str()); break;
					case 10: juiceP = std::atof(numberHolder.c_str()); break;
					case 11: waterP = std::atof(numberHolder.c_str()); break;
					case 12: yeastMass = std::atof(numberHolder.c_str()); break;
					case 13: sucroseMass = std::atof(numberHolder.c_str()); break;
					case 14: juiceLitre = std::atof(numberHolder.c_str()); break;
					case 15: waterLitre = std::atof(numberHolder.c_str()); break;
					case 16: timeSpan = std::atof(numberHolder.c_str()); break;
					case 17: monosaccharidegL = std::atof(numberHolder.c_str()); break;
					case 18: disaccharidegL = std::atof(numberHolder.c_str()); break;
					case 19: carbondioxidegL = std::atof(numberHolder.c_str()); break;
					case 20: ethanolgL = std::atof(numberHolder.c_str()); break;
					case 21: watergL = std::atof(numberHolder.c_str()); break;
					case 22: hydrogenM = std::atof(numberHolder.c_str()); break;
					case 23: carbonM = std::atof(numberHolder.c_str()); break;
					case 24: oxygenM = std::atof(numberHolder.c_str()); break;
					case 25: yeastPL = std::atof(numberHolder.c_str()); break;
					case 26: ethanolEoC = std::atof(numberHolder.c_str()); break;
					case 27: sucroseEoC = std::atof(numberHolder.c_str()); break;
				}
				termCounter++;
				numberHolder.clear();
			}
		}
		/*case 27: */sucroseEoC = std::atof(numberHolder.c_str());
		actual.close();

}

int Load::enter(sf::Sprite &screenS)
{
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


		createList();
		overlay1.clear(sf::Color(0,127,0,200));
		while (list.size() > currentElement)
		{
			overlay1.draw(list.at(currentElement));
			currentElement++;
		}
		overlay1.display();
		currentElement = 0;
		updateTimer();
		overlay2.clear(sf::Color(0,127,0,200));
		while (list.size() > currentElement)
		{
			overlay2.draw(timeList.at(currentElement));
			currentElement++;
		}
		overlay2.display();
		currentElement = 0;
		sf::Clock timer;
		sf::Event event;
		begin:
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					return 1;
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Escape:
							timeTable.clear();
							return 0;
							break;
						case sf::Keyboard::Up:
							if (selection > 1)
							{
								marker.move(0,-10);
								selection--;
							}
							else
							{
								if (list.size() > 2)
									selection = list.size() - 2;
								marker.setPosition(100,selection * 10 + 77);
							}
							break;
						case sf::Keyboard::Down:
							if (selection < list.size() - 2)
							{
								marker.move(0,10);
								selection++;
							}
							else
							{
								selection = 1;
								marker.setPosition(100,87);
							}
							break;
						case sf::Keyboard::Return:
							if (lastLoaded >= 0)
								list[lastLoaded].setColor(sf::Color::White);
							list[selection].setColor(sf::Color::Cyan);
							lastLoaded = selection;
							timeSpan = timeTable[selection];
							{
								std::string temporary = static_cast<std::string>(list[selection].getString()) + ".txt";
								temporary.erase(temporary.begin());
								name = temporary; name.erase(name.size() - 1); name.erase(name.size() - 1); name.erase(name.size() - 1); name.erase(name.size() - 1);
								temporary = "save/" + temporary;
								std::fstream actual(temporary.c_str());
								unsigned int termCounter = 0;
								std::string numberHolder;
								while (actual.good())
								{
									char temp = actual.get();
									if ((temp >= 48 && temp <= 57) || temp == 46)
										numberHolder.push_back(temp);
									else if (temp == 10)
									{
										switch (termCounter)
										{
											case 0: totalVolume = std::atof(numberHolder.c_str()); break;
											case 1: totalDiSugarPerLitre = std::atof(numberHolder.c_str()); break;
											case 2: juiceVolume = std::atof(numberHolder.c_str()); break;
											case 3: juiceMonoSugarPerLitre = std::atof(numberHolder.c_str()); break;
											case 4: juiceDiSugarPerLitre = std::atof(numberHolder.c_str()); break;
											case 5: startMass = std::atof(numberHolder.c_str()); break;
											case 6: finalMass = std::atof(numberHolder.c_str()); break;
											case 7: volumeB = std::atof(numberHolder.c_str()); break;
											case 8: yeastP = std::atof(numberHolder.c_str()); break;
											case 9: sucroseP = std::atof(numberHolder.c_str()); break;
											case 10: juiceP = std::atof(numberHolder.c_str()); break;
											case 11: waterP = std::atof(numberHolder.c_str()); break;
											case 12: yeastMass = std::atof(numberHolder.c_str()); break;
											case 13: sucroseMass = std::atof(numberHolder.c_str()); break;
											case 14: juiceLitre = std::atof(numberHolder.c_str()); break;
											case 15: waterLitre = std::atof(numberHolder.c_str()); break;
											case 16: timeSpan = std::atof(numberHolder.c_str()); break;
											case 17: monosaccharidegL = std::atof(numberHolder.c_str()); break;
											case 18: disaccharidegL = std::atof(numberHolder.c_str()); break;
											case 19: carbondioxidegL = std::atof(numberHolder.c_str()); break;
											case 20: ethanolgL = std::atof(numberHolder.c_str()); break;
											case 21: watergL = std::atof(numberHolder.c_str()); break;
											case 22: hydrogenM = std::atof(numberHolder.c_str()); break;
											case 23: carbonM = std::atof(numberHolder.c_str()); break;
											case 24: oxygenM = std::atof(numberHolder.c_str()); break;
											case 25: yeastPL = std::atof(numberHolder.c_str()); break;
											case 26: ethanolEoC = std::atof(numberHolder.c_str()); break;
											case 27: sucroseEoC = std::atof(numberHolder.c_str()); break;
										}
										termCounter++;
										numberHolder.clear();
									}
								}
								/*case 27: */sucroseEoC = std::atof(numberHolder.c_str());
								actual.close();
								///For changing the color:
								overlay1.clear(sf::Color(0,127,0,200));
								while (list.size() > currentElement)
								{
									overlay1.draw(list.at(currentElement));
									currentElement++;
								}
								overlay1.display();
								currentElement = 0;
							}
							break;
						case sf::Keyboard::Delete:
						{
							//Deletes the file in the save folder. Simple, easy.
							std::string midler = static_cast<std::string>(list[selection].getString()); //We fetch the name from the list
							midler.erase(midler.begin()); //We need to erase the first element because it's a space
							midler = "\n" + midler + ",";
							///Deleting the entry from the load list:
							loadList.open("loadList.txt", std::ios::in);
							std::string fileMem, newMem;
							while (loadList.good())
							{
								fileMem.push_back(loadList.get()); //Load the entire file into memory
							}
							int location = (int)fileMem.find(midler.c_str()) + 1; //Now we found the entry point of the string to be deleted.
							loadList.close();
							bool check1 = false; unsigned int telleg = 0, fileMemSize = (unsigned int) fileMem.size();
							while (fileMemSize > telleg)
							{
								char hold = fileMem[telleg];
								if (telleg == location)
									check1 = true;
								telleg++;
								if (check1)
								{
									if (hold == '\n')
										check1 = false;
								}
								else
									newMem.push_back(hold);
							}
							loadList.open("loadList.txt", std::ios::out | std::ios::trunc);
							loadList.write(newMem.c_str(), newMem.size() - 1);
							loadList.close();

							midler.erase(midler.begin());
							midler.erase(midler.end() - 1);
							midler = ("save/" + midler + ".txt");
							std::remove(midler.c_str()); //And thus the file is removed

							createList();
							if (selection < lastLoaded)
							{
								list[lastLoaded].setColor(sf::Color::White);
								lastLoaded--;
								list[lastLoaded].setColor(sf::Color::Cyan);
							}
							else if (selection == lastLoaded)
							{
								list[lastLoaded].setColor(sf::Color::White);
							}
							overlay1.clear(sf::Color(0,127,0,200));
							while (list.size() > currentElement)
							{
								overlay1.draw(list.at(currentElement));
								currentElement++;
							}
							overlay1.display();
							currentElement = 0;
						   // updateTimer();
							overlay2.clear(sf::Color(0,127,0,200));
							while (list.size() > currentElement)
							{
								overlay2.draw(timeList.at(currentElement));
								currentElement++;
							}
							overlay2.display();
							currentElement = 0;
							if (selection == list.size() - 1 && selection != 1)
							{
								selection--;
								marker.setPosition(100,selection * 10 + 77);
							}
						}
							break;
						default: break;
					}
					break;
				default: break;
			}
		}
		if (timer.getElapsedTime().asSeconds() >= 1.f)
		{
			timer.restart();
			updateTimer();
			overlay2.clear(sf::Color(0,127,0,200));
			while (list.size() > currentElement)
			{
				overlay2.draw(timeList.at(currentElement));
				currentElement++;
			}
			overlay2.display();
			currentElement = 0;
		}
		window.clear();
		window.draw(screenS);
		window.draw(overlayS1);
		window.draw(overlayS2);
		window.draw(marker);
		window.draw(toppy);
		window.draw(notification);
		window.display();

		goto begin;
		return 1;
}
