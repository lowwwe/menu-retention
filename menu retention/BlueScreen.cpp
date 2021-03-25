#include "BlueScreen.h"
#include "Game.h"

void BlueScreen::render(sf::RenderWindow& t_window)
{
	t_window.clear(sf::Color::Blue);
	t_window.draw(m_title);
	t_window.display();

}

void BlueScreen::processEnevt(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Space == t_event.key.code)
		{
			m_leaving = true;
			m_countdown = 15;
		}
	}
}

void BlueScreen::update(sf::Time t_deltaTime)
{
	if (m_leaving)
	{
		if (m_countdown-- < 0)
		{
			Game::s_currentMode = GameMode::Red;
			m_leaving = false;
			m_title.setFillColor(sf::Color::White);
		}
		m_title.setFillColor(m_title.getFillColor() - sf::Color{ 5,5,5,0 });
	}
}

void BlueScreen::initialise()
{
m_font = Game::s_font;
m_title.setFont(m_font);
m_title.setString("Blue Page \npress space to change");
m_title.setPosition(300.0f, 50.0f);
m_title.setCharacterSize(16);
m_title.setFillColor(sf::Color::White);
}
