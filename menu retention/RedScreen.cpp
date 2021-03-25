#include "RedScreen.h"
#include "Game.h"

void RedScreen::render(sf::RenderWindow& t_window)
{
	t_window.clear(m_bgColour);
	t_window.draw(m_title);
	for (int i = 0; i < 3; i++)
	{
		menu[i].render(t_window);
	}
	t_window.display();

}


/// <summary>
/// in here we will react to the button presses
/// </summary>
/// <param name="t_event"></param>
void RedScreen::processEnevt(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Space == t_event.key.code)
		{
			m_leaving = true;
			m_countdown = 15;
		}
	}

		if (menu[0].processInput(t_event))
		{
			m_leaving = true;
			m_countdown = 15;
		}
		if (menu[1].processInput(t_event))
		{
			m_bgColour = sf::Color::Cyan;
		}
		if (menu[2].processInput(t_event))
		{
			m_bgColour = sf::Color::Red;
		}
}


/// <summary>
/// countdown timer is leaving and
/// update for menu for rollover effects
/// </summary>
/// <param name="t_deltaTime"></param>
/// <param name="t_window"></param>
void RedScreen::update(sf::Time t_deltaTime, sf::RenderWindow& t_window)
{
	if (m_leaving)
	{
		if (m_countdown-- < 0)
		{
			Game::s_currentMode = GameMode::Blue;
			m_leaving = false;
			m_title.setFillColor(sf::Color::White);
		}
		m_title.setFillColor(m_title.getFillColor() - sf::Color{ 5,5,5,0 });
	}
	for (int i = 0; i < 3; i++)
	{
		menu[i].update(t_deltaTime,t_window);
	}
}

void RedScreen::initialise()
{
	m_font = Game::s_font;
	m_title.setFont(m_font);
	m_title.setString("Red Page \npress space to change");
	m_title.setPosition(300.0f, 50.0f);
	m_title.setCharacterSize(16);
	m_title.setFillColor(sf::Color::White);
	menu[0].initialise("Goto the blue screen", sf::Vector2f{ 200.0f, 200.0f });
	menu[1].initialise("Make this screen Cyan", sf::Vector2f{ 200.0f, 300.0f });
	menu[2].initialise("Make this screen Red", sf::Vector2f{ 200.0f, 400.0f });
}
