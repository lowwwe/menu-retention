#pragma once
#include <SFML/Graphics.hpp>

//simple page and thre menu items

#include "MenuItem.h"

class RedScreen
{
public:
	void render(sf::RenderWindow& t_window);
	void processEnevt(sf::Event t_event);
	void update(sf::Time t_deltaTime, sf::RenderWindow& t_window);
	void initialise();


private:
	sf::Font m_font;
	sf::Text m_title;
	bool m_leaving = false;
	int m_countdown = 15;
	MenuItem menu[3];
	sf::Color m_bgColour = sf::Color::Red;
};

