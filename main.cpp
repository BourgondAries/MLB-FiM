#include <SFML/Graphics.hpp>
#include <cstdio>
#include "icon.hpp"
#include "about.hpp"
#include "economy.hpp"
#include "recipe.hpp"
const char * auth = "Gemaakt door de Nederlander Kevin Robert Stravers (1994, september, 25), volmaakt op de negende van oktober, 2012, gedurende 5 dagen";

typedef const std::size_t usize;

double molarMass(int h, int c, int o, Comchan &comchan) {
	return h * comchan.hydrogenM + c * comchan.carbonM +
		o * comchan.oxygenM;
}

void initComchanMolars(Comchan &comchan) {
	comchan.carbonM = 12.0107;
	comchan.hydrogenM = 1.008;
	comchan.oxygenM = 15.9994;
	comchan.carbondioxideM = molarMass(0,1,2, comchan);
	comchan.ethanolM = molarMass(6,2,1, comchan);
	comchan.waterM = molarMass(2,0,1, comchan);
	comchan.monosaccharideM = molarMass(12,6,6, comchan);
	comchan.disaccharideM = molarMass(22,12,11, comchan);

	comchan.ethanolEoC = 1058000;
	comchan.sucroseEoC = 5648000;
	comchan.enthalpyC = comchan.sucroseEoC - comchan.ethanolEoC*4;

	comchan.watergL = 1000;
	comchan.ethanolgL = 789;
	comchan.carbondioxidegL = 1.98;
	comchan.disaccharidegL = 1590;
	comchan.monosaccharidegL = 1540;

}

int main() {
	sf::RectangleShape backGround;
	sf::Event event;
	sf::Font font;
	sf::RenderWindow window;
	sf::Sprite screenS;

	Comchan communicator;
	initComchanMolars(communicator);

	char selection = (char)0;
	usize menu_item_count = 7;
	sf::Text menu[menu_item_count];
	sf::Texture backy, banny;
	sf::Sprite backys, bannys;
	font.loadFromFile("visitor1.ttf");

	About about(window, font);
	Economy economy(window, font, communicator);
	Recipe recipe(window, font, communicator, backGround);

	backy.loadFromFile("data/menu0.png"); banny.loadFromFile("data/menu1.png");
	backys.setTexture(backy); bannys.setTexture(banny);
	bannys.setPosition(200,0);
	menu[0].setString("Recipe"); menu[1].setString("Product"); menu[2].setString("Economy"); menu[3].setString("Load"); menu[4].setString("Save"); menu[5].setString("About"); menu[6].setString("Exit");
	menu[0].setCharacterSize(20);
	menu[0].setFont(font);
	menu[0].setColor(sf::Color(127,127,127));
	menu[0].setPosition(sf::Vector2f(800 / 2 - (int)menu[0].getGlobalBounds().width / 2, 400));
	for (int i = 1; i < menu_item_count; i++)
	{
		menu[i].setCharacterSize(20);
		menu[i].setFont(font);
		menu[i].setColor(sf::Color(127,127,127));
		menu[i].setPosition(sf::Vector2f(800 / 2. - (int)menu[i].getGlobalBounds().width / 2, menu[i-1].getPosition().y + 20));
	}
	menu[0].setColor(sf::Color(255,255,255));
	window.setFramerateLimit(30);
	window.create(sf::VideoMode(800,600,32), "My Little Brew : Fermentation is Magic", sf::Style::Default);
	window.clear();
	window.draw(backys);
	window.draw(backGround);
	for (int i = 0; i < menu_item_count; i++)
		window.draw(menu[i]);
	window.draw(bannys);
	window.display();
	window.setIcon(beer.width, beer.height, beer.pixel_data);
	while (window.isOpen())
	{
		invalid:
		if (window.waitEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu[(int)selection].setColor(sf::Color(127,127,127));
							if (selection == (char) 0)
								selection = (char) 6;
							else
								selection--;
							menu[(int)selection].setColor(sf::Color(255,255,255));
							break;
						case sf::Keyboard::Down:
							menu[(int)selection].setColor(sf::Color(127,127,127));
							if (selection == (char) 6)
								selection = (char) 0;
							else
								selection++;
							menu[(int)selection].setColor(sf::Color(255,255,255));
							break;
						case sf::Keyboard::Return:
							switch ((int)selection)
							{
								case 0:
									if (recipe.enter() == 1)
										return 0;
									break;
								case 1:
									// if (product() == 1)
										return 0;
									break;
								case 2:
									if (economy.enter(backGround) == 1)
										return 0;
									break;
								case 3:
									{
										window.clear();
										window.draw(backys);
										window.draw(backGround);
										for (int i = 0; i < menu_item_count; i++)
											window.draw(menu[i]);
										window.draw(bannys);
										window.display();

										sf::Image screen = window.capture();
										sf::Texture screenT; screenT.loadFromImage(screen);
										screenS.setTexture(screenT);
										// if (load() == 1)
											return 0;
									}
									break;
								case 4:
									{
										window.clear();
										window.draw(backys);
										window.draw(backGround);
										for (int i = 0; i < menu_item_count; i++)
											window.draw(menu[i]);
										window.draw(bannys);
										window.display();

										sf::Image screen = window.capture();
										sf::Texture screenT; screenT.loadFromImage(screen);
										screenS.setTexture(screenT);
										// if (save() == 1)
											return 0;
									}
									break;
								case 6:
									window.close();
									return 0;
									break;
								default:
								{
									window.clear();
									window.draw(backys);
									window.draw(backGround);
									for (int i = 0; i < menu_item_count; i++)
										window.draw(menu[i]);
									window.draw(bannys);
									window.display();

									sf::Image screen = window.capture();
									sf::Texture screenT; screenT.loadFromImage(screen);
									screenS.setTexture(screenT);
									if (about.enter(screenS) == 1)
										return 0;
								}
									break;
							}
							break;
						case sf::Keyboard::Escape:
							window.close();
							return 0;
						case sf::Keyboard::L:
						{
							window.clear();
							window.draw(backys);
							window.draw(backGround);
							for (int i = 0; i < menu_item_count; i++)
								window.draw(menu[i]);
							window.draw(bannys);
							window.display();

							sf::Image screen = window.capture();
							sf::Texture screenT; screenT.loadFromImage(screen);
							screenS.setTexture(screenT);
							// load();
						}
							break;
						case sf::Keyboard::S:
						{
							window.clear();
							window.draw(backys);
							window.draw(backGround);
							for (int i = 0; i < menu_item_count; i++)
								window.draw(menu[i]);
							window.draw(bannys);
							window.display();

							sf::Image screen = window.capture();
							sf::Texture screenT; screenT.loadFromImage(screen);
							screenS.setTexture(screenT);
							// save();
						}
							break;
						default: ;
					}
					break;
				case sf::Event::Closed:
					window.close();
					return 0;
				default: goto invalid;
			}
		}
		window.clear();
		window.draw(backys);
		window.draw(backGround);
		for (int i = 0; i < menu_item_count; i++)
			window.draw(menu[i]);
		window.draw(bannys);
		window.display();
	}
	return 0;
}
