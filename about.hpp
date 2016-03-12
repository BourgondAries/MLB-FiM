#include <SFML/Graphics.hpp>

class About {
	sf::Text noter, thanks, progry;
	sf::Texture logo1[6];
	sf::Sprite logo2[6];
	sf::RectangleShape fader, lineh, linev;
	sf::RenderWindow &window;

public:

	About(sf::RenderWindow &window, const sf::Font &font);
	int enter(sf::Sprite &screenS);

};
