#pragma once
#include <SFML/Graphics.hpp>

// simple page
class BlueScreen
{
public:
	void render(sf::RenderWindow& t_window);
	void processEnevt(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void initialise();

private:
	sf::Font m_font;
	sf::Text m_title;
	bool m_leaving = false;
	int m_countdown = 15;
};

