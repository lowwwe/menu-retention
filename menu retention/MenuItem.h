#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuItem
{
public:
	bool m_highlighted;
	bool m_pressed;
	void initialise(std::string t_text, sf::Vector2f t_position);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltatime, sf::RenderWindow& t_window);
	bool processInput(sf::Event t_event);
	static sf::Texture s_buttonTexture;
	static sf::SoundBuffer s_rolloverSound;
	static sf::SoundBuffer s_mouseDownSound;
	static sf::SoundBuffer s_mouseCLickSound;
	static void loadAssets();

private:
	sf::Sprite m_button;
	sf::Vector2f m_topLeft;
	sf::FloatRect m_area;
	sf::Text m_text;
	sf::Sound m_mouseOverSound;
	sf::Sound m_mousedownSound;
	sf::Sound m_mouseClickSound;

	
};

