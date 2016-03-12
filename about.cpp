#include "about.hpp"
#include <SFML/Graphics.hpp>

void About::About(sf::RenderWindow &window, const sf::Font &font)
:
	window(window) {
		noter.setFont(font); thanks.setFont(font); progry.setFont(font);
		noter.setCharacterSize(10); thanks.setCharacterSize(20); progry.setCharacterSize(10);
		noter.setString(" My name is Kevin and I reside in the Kingdom of Norway. I wanted to\ncreate this program because of my mutual interests in programming\nand brewing. Before I made this, I was a simple console programmer\nand made a small calculation application, this is a major improvement\nthereof.\n\nDuring the programming of this application, I learned:\nA lot about GIMP 2.8, I had to edit all pictures (crop, clean...)\nadditional C++ (mostly STL)\nadditional SFML 2.0 RC\nAdditional Input/Output with files\nData sorting\nProgram Design\n\nThese are the last lines I'm writing,\nsometimes I wonder why I'm even\ndoing this. Oh well...\n\nDo I watch My Little Pony : FiM?\n - Yes, I do, and I loved it!\n\n\n\n\n\n - Applejack is best pony :P\n\n\n\n\nPS: Shortcuts: S to save, L to load.\n\n\n\n\n\n\n\n\n\nAll metric system / SI units."); thanks.setString("Thanks to:"); progry.setString("This program is coded using C++ whilst utilizing Code::Blocks' 10.05 STL\npackage and the SFML 2.0 Release Candidate C++ binding library for\nwindowing, event handling, and graphics. The program utilizes molar\ncalculations to get the most precise values on the table. Do note\nthat all of the calculations are the theorethical maximum. For\nexample, in the Product window, you may see the ABV and EPL,\nhowever, these values take for granted that all the lost mass\nduring fermentation is carbondioxide, and do not take into account\nother gases, such as dihydrogensulfide.\n\nNavigation uses enter/return, arrow keys, and escape.\nInput utilizes number keys and arrow keys.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe icons from left to right:\nSFML-2.0\tCode::Blocks 10.05\tC++ unofficial\tMLP:FiM\n");
		noter.setPosition(10,0); thanks.setPosition((int)400 - thanks.getGlobalBounds().width / 2.,420); progry.setPosition(410,0);

		logo1[0].loadFromFile("data/sfml-small.png"); logo1[1].loadFromFile("data/codeblocks.png"); logo1[2].loadFromFile("data/cpp-logo.png"); logo1[3].loadFromFile("data/G4.png"); logo1[4].loadFromFile("data/about0.png"); logo1[5].loadFromFile("data/about1.png");
		for (int i = 0; i < 6; i++)
				logo2[i].setTexture(logo1[i]);
		logo2[0].setPosition(60,600 - logo2[0].getGlobalBounds().height);
		logo2[1].setPosition(logo2[0].getGlobalBounds().width + logo2[0].getGlobalBounds().left + 40, 600 - logo2[1].getGlobalBounds().height);
		logo2[2].setPosition(logo2[1].getGlobalBounds().width + logo2[1].getGlobalBounds().left + 40, 600 - logo2[2].getGlobalBounds().height);
		logo2[3].setPosition(logo2[2].getGlobalBounds().width + logo2[2].getGlobalBounds().left + 40, 600 - logo2[3].getGlobalBounds().height);

		logo2[4].setPosition(150,139); logo2[5].setPosition(420,114);

		fader.setSize(sf::Vector2f(800,600));
		fader.setFillColor(sf::Color(127,127,127,170));
		lineh.setSize(sf::Vector2f(800,3)); linev.setSize(sf::Vector2f(3,400));
		lineh.setPosition(0,400); linev.setPosition(400,0);
	}

int About::enter(sf::Sprite &screenS) {
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
					case sf::Keyboard::Escape:
						return 0;
						break;
					default: break;
				}
				break;
			default: break;
		}
	}

	window.clear();

	window.draw(screenS);
	window.draw(fader);
	window.draw(noter);
	window.draw(thanks);
	window.draw(progry);
	for (int i = 0; i < 6; ++i)
		window.draw(logo2[0]);
	window.draw(linev);
	window.draw(lineh);

	window.display();

	goto begin;
	return 1;
}
