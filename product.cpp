#include "product.hpp"
#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include <string>
#include <cstdlib>

std::string n2s(double);

void Product::calculate()
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


	carbonDMol = (startMass - finalMass) / carbondioxideM; carbonDMass = carbonDMol * carbondioxideM; carbonDVolume = carbonDMass / carbondioxidegL;
	ethanolMol = carbonDMol; ethanolMass = ethanolMol * ethanolM; ethanolVolume = ethanolMass / ethanolgL;
	ABV = (ethanolVolume / volumeB) * 100;
	EPL = ethanolMass / volumeB;
	///Updating graphics:
	startMass_.setString(startMass_0 + n2s(startMass));
	finalMass_.setString(finalMass_0 + n2s(finalMass));
	volumeB_.setString(volumeB_0 + n2s(volumeB));

	carbonDMol_.setString(carbonD_0 + n2s(carbonDMol)); carbonDMass_.setString(carbonD_0 + n2s(carbonDMass)); carbonDVolume_.setString(carbonD_0 + n2s(carbonDVolume));
	ethanolMol_.setString(ethanol_0 + n2s(ethanolMol)); ethanolMass_.setString(ethanol_0 + n2s(ethanolMass)); ethanolVolume_.setString(ethanol_0 + n2s(ethanolVolume));
	ABV_.setString(ABV_0 + n2s(ABV) + std::string("%"));
	EPL_.setString("EPL: " + n2s(EPL));
}

Product::Product(sf::RenderWindow &window, sf::Font &font, Comchan &comchan, sf::RectangleShape &backGround)
:
	window(window),
	font(font),
	comchan(comchan),
	backGround(backGround)
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


	input.setFont(font); mol.setFont(font); mass.setFont(font); volume.setFont(font); misc.setFont(font); startMass_.setFont(font); finalMass_.setFont(font); volumeB_.setFont(font);
	carbonDMol_.setFont(font); carbonDMass_.setFont(font); carbonDVolume_.setFont(font); ethanolMol_.setFont(font); ethanolMass_.setFont(font); ethanolVolume_.setFont(font);
	ABV_.setFont(font); EPL_.setFont(font);
	info.setFont(font);

	input.setCharacterSize(10); mol.setCharacterSize(10); mass.setCharacterSize(10); volume.setCharacterSize(10); misc.setCharacterSize(10); startMass_.setCharacterSize(10); finalMass_.setCharacterSize(10); volumeB_.setCharacterSize(10);
	carbonDMol_.setCharacterSize(10); carbonDMass_.setCharacterSize(10); carbonDVolume_.setCharacterSize(10); ethanolMol_.setCharacterSize(10); ethanolMass_.setCharacterSize(10); ethanolVolume_.setCharacterSize(10);
	ABV_.setCharacterSize(10); EPL_.setCharacterSize(10);
	info.setCharacterSize(10);

	input.setPosition(800 * (15. / 48.),posDeviation); startMass_.setPosition(800 * (15. / 48.),10 + posDeviation); finalMass_.setPosition(800 * (15. / 48.),20 + posDeviation); volumeB_.setPosition(800 * (15. / 48.),30 + posDeviation);
	startMass_.setColor(sf::Color::Yellow); finalMass_.setColor(sf::Color(127,127,127)); volumeB_.setColor(sf::Color(127,127,127));
	mol.setPosition(800 / 2., posDeviation); carbonDMol_.setPosition(800 / 2., 10 + posDeviation); ethanolMol_.setPosition(800 / 2., 20 + posDeviation);
	mass.setPosition(800 * (15. / 48.), 50 + posDeviation); carbonDMass_.setPosition(800 * (15. / 48.), 60 + posDeviation); ethanolMass_.setPosition(800 * (15. / 48.), 70 + posDeviation);
	volume.setPosition(800 / 2., 50 + posDeviation); carbonDVolume_.setPosition(800 / 2., 60 + posDeviation); ethanolVolume_.setPosition(800 / 2., 70 + posDeviation);
	misc.setPosition(800 * (15. / 48.), 90 + posDeviation); ABV_.setPosition(800 * (15. / 48.), 100 + posDeviation); EPL_.setPosition(800 / 2., 100 + posDeviation);
	info.setPosition(800 * (15. / 48.), 120 + posDeviation);
	input.setString(std::string("input")); mol.setString(std::string("mol")); mass.setString(std::string("mass")); volume.setString(std::string("volume")); misc.setString(std::string("misc."));
	info.setString("This is for post-fermentation calculations only,\nbut it would be wise to save the mass of the\npre-fermentation mixture in order to actually use\nthe above results. You can input any start mass\nand save this as a batch, it'll be there still\nwhen you load it. The mass is in grams, the\nvolume in litres.\n\nStart Mass: Mass of the wort (pre-fermentation mixture)\nFinal Mass: mass of the final product\nVolume: Final volume of the product\nABV = Alcohol % by Volume\nEPL = Ethanol (gram) per litre\nWhen calculating using specific gravity, change volume\nto 0.001. Use start mass as S.G. and final mass as F.G.");

	backGroundT.loadFromFile("data/product0.png"); bannerT.loadFromFile("data/product1.png");
	backGroundS.setTexture(backGroundT); bannerS.setTexture(bannerT); bannerS.setPosition(200,0);

	calculate();
}

int Product::enter() {
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

	begin:
	sf::Event event;
	if (window.waitEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				return 1;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Up:
						switch ((int)selection)
						{
							case 0:
								selection = (char)2;
								startMass_.setColor(sf::Color(127,127,127));
								volumeB_.setColor(sf::Color::Yellow);
								break;
							case 1:
								selection--;
								finalMass_.setColor(sf::Color(127,127,127));
								startMass_.setColor(sf::Color::Yellow);
								break;
							case 2:
								selection--;
								volumeB_.setColor(sf::Color(127,127,127));
								finalMass_.setColor(sf::Color::Yellow);
								break;
							default: selection = (char) 0; break;
						}
						calculate();
						if (enterN)
							instream.clear();
						enterN = false;
						hasPer = false;
						break;
					case sf::Keyboard::Down:
						switch ((int)selection)
						{
							case 0:
								selection++;
								startMass_.setColor(sf::Color(127,127,127));
								finalMass_.setColor(sf::Color::Yellow);
								break;
							case 1:
								selection++;
								finalMass_.setColor(sf::Color(127,127,127));
								volumeB_.setColor(sf::Color::Yellow);
								break;
							case 2:
								selection = (char) 0;
								volumeB_.setColor(sf::Color(127,127,127));
								startMass_.setColor(sf::Color::Yellow);
								break;
							default: selection = (char) 0; break;
						}
						calculate();
						if (enterN)
							instream.clear();
						enterN = false;
						hasPer = false;
						break;
					case sf::Keyboard::Left:
						switch ((int)selection)
						{
							case 0:
								if (startMass > 0.09)
									startMass -= 1.;
								break;
							case 1:
								if (finalMass > 0.09)
									finalMass -= 1.;
								break;
							case 2:
								if (volumeB >= 0.09)
									volumeB -= 0.1;
								break;
							default: selection = (char) 0; break;
						}
						calculate();
						if (enterN)
							instream.clear();
						enterN = false;
						hasPer = false;
						break;
					case sf::Keyboard::Right:
						switch ((int)selection)
						{
							case 0:
									startMass += 1.;
								break;
							case 1:
								if (finalMass < startMass)
									finalMass += 1.;
								break;
							case 2:
									volumeB += .1;
								break;
							default: selection = (char) 0; break;
						}
						calculate();
						if (enterN)
							instream.clear();
						enterN = false;
						hasPer = false;
						break;
					case sf::Keyboard::Return:
						calculate();
						if (enterN)
							instream.clear();
						hasPer = false;
						enterN = false;
						break;
					case sf::Keyboard::Num0:
					{
						instream.push_back(event.key.code + (char) 22);
						enterN = true;
						if (hasPer)
							switch ((int)selection)
							{
								case 0: startMass = std::atof(instream.c_str()); startMass_.setString(startMass_.getString() + "0"); break;
								case 1: finalMass = std::atof(instream.c_str()); finalMass_.setString(finalMass_.getString() + "0"); break;
								case 2: volumeB = std::atof(instream.c_str()); volumeB_.setString(volumeB_.getString() + "0"); break;
								default: break;
							}
						else
						{
							switch ((int)selection)
							{
								case 0: startMass = std::atof(instream.c_str()); break;
								case 1: finalMass = std::atof(instream.c_str()); break;
								case 2: volumeB = std::atof(instream.c_str()); break;
								default: break;
							}
							calculate();
						}
					}
						break;
					case sf::Keyboard::Num1:
					case sf::Keyboard::Num2:
					case sf::Keyboard::Num3:
					case sf::Keyboard::Num4:
					case sf::Keyboard::Num5:
					case sf::Keyboard::Num6:
					case sf::Keyboard::Num7:
					case sf::Keyboard::Num8:
					case sf::Keyboard::Num9:
					{
						instream.push_back(event.key.code + (char) 22);
						enterN = true;
						switch ((int)selection)
						{
							case 0: startMass = std::atof(instream.c_str()); break;
							case 1: finalMass = std::atof(instream.c_str()); break;
							case 2: volumeB = std::atof(instream.c_str()); break;
							default: break;
						}
						calculate();
					}
						break;
					case sf::Keyboard::Period:
					{
						if (hasPer)
							goto localExit;
						instream.push_back((char) 46);
						hasPer = true;
						if (!enterN) // If there is a re-newal.
						{
							switch ((int)selection)
							{
								case 0: startMass = 0; break;
								case 1: finalMass = 0; break;
								case 2: volumeB = 0; break;
								default: break;
							}
							calculate();
							enterN = true;
							switch ((int)selection)
							{
								case 0: startMass_.setString(startMass_0 + n2s(startMass) + std::string(".")); break;
								case 1: finalMass_.setString(finalMass_0 + n2s(finalMass) + std::string(".")); break;
								case 2: volumeB_.setString(volumeB_0 + n2s(volumeB) + std::string(".")); break;
								default: break;
							}
						}
						else //When we are adding a "." to an already being-written number
						{
							switch ((int)selection)
							{
								case 0: startMass_.setString(startMass_0 + n2s(startMass) + std::string(".")); break;
								case 1: finalMass_.setString(finalMass_0 + n2s(finalMass) + std::string(".")); break;
								case 2: volumeB_.setString(volumeB_0 + n2s(volumeB) + std::string(".")); break;
								default: break;
							}
						}
						localExit:;
					}
					break;
					case sf::Keyboard::BackSpace:
					{
							instream.clear();
							switch ((int)selection)
							{
								case 0: startMass = std::atof(instream.c_str()); break;
								case 1: finalMass = std::atof(instream.c_str()); break;
								case 2: volumeB = std::atof(instream.c_str()); break;
								default: break;
							}
							calculate();
							enterN = true;
							hasPer = false;
					}
					break;
					case sf::Keyboard::Escape:
						if (enterN)
							instream.clear();
						return 0;
					case sf::Keyboard::L:
					{
						 window.clear();

						window.draw(backGroundS);
						window.draw(backGround);

						window.draw(input);
						window.draw(startMass_);
						window.draw(finalMass_);
						window.draw(volumeB_);

						window.draw(mol);
						window.draw(carbonDMol_);
						window.draw(ethanolMol_);

						window.draw(mass);
						window.draw(carbonDMass_);
						window.draw(ethanolMass_);

						window.draw(volume);
						window.draw(carbonDVolume_);
						window.draw(ethanolVolume_);

						window.draw(misc);
						window.draw(ABV_);
						window.draw(EPL_);

						window.draw(info);

						window.draw(bannerS);

						window.display();


						sf::Image screen = window.capture();
						sf::Texture screenT; screenT.loadFromImage(screen);
						sf::Sprite screenS;
						screenS.setTexture(screenT);
						// load();
					}

						break;
					case sf::Keyboard::S:
					{
						 window.clear();

						window.draw(backGroundS);
						window.draw(backGround);

						window.draw(input);
						window.draw(startMass_);
						window.draw(finalMass_);
						window.draw(volumeB_);

						window.draw(mol);
						window.draw(carbonDMol_);
						window.draw(ethanolMol_);

						window.draw(mass);
						window.draw(carbonDMass_);
						window.draw(ethanolMass_);

						window.draw(volume);
						window.draw(carbonDVolume_);
						window.draw(ethanolVolume_);

						window.draw(misc);
						window.draw(ABV_);
						window.draw(EPL_);

						window.draw(info);

						window.draw(bannerS);

						window.display();


						sf::Image screen = window.capture();
						sf::Texture screenT; screenT.loadFromImage(screen);
						sf::Sprite screenS;
						screenS.setTexture(screenT);
						// save();
					}
						break;
					default: break;
				}
			break;
			default: break;
		}
	}
	window.clear();

	window.draw(backGroundS);
	window.draw(backGround);

	window.draw(input);
	window.draw(startMass_);
	window.draw(finalMass_);
	window.draw(volumeB_);

	window.draw(mol);
	window.draw(carbonDMol_);
	window.draw(ethanolMol_);

	window.draw(mass);
	window.draw(carbonDMass_);
	window.draw(ethanolMass_);

	window.draw(volume);
	window.draw(carbonDVolume_);
	window.draw(ethanolVolume_);

	window.draw(misc);
	window.draw(ABV_);
	window.draw(EPL_);

	window.draw(info);

	window.draw(bannerS);

	window.display();
	goto begin;
	return 1;
}
