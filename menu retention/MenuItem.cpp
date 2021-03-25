#include "MenuItem.h"
#include "Game.h"
#include <iostream>

/// <summary>
/// setup a new menu item
/// </summary>
/// <param name="t_text"></param>
/// <param name="t_position"></param>
void MenuItem::initialise(std::string t_text, sf::Vector2f t_position)
{
    m_button.setPosition(t_position);
    m_button.setTexture(MenuItem::s_buttonTexture);
    m_topLeft = t_position;
    m_text.setString(t_text);
    m_text.setFont(Game::s_font);
    m_text.setCharacterSize(25);
    m_text.setFillColor(sf::Color::Black);
    m_area = m_text.getGlobalBounds();
    m_text.setPosition(t_position + sf::Vector2f{ 10.0f,m_area.height/2.0f }); // offset the text from the top left of button
    m_area = m_text.getGlobalBounds();
    m_area.height += 30; // make the button bit larger than the global bound of the text
    m_area.width += 30;
    float xRatio = m_area.width / MenuItem::s_buttonTexture.getSize().x;

    
    m_button.setScale(xRatio, m_area.height / static_cast<float>(MenuItem::s_buttonTexture.getSize().y));
    
    m_mouseOverSound.setBuffer(s_rolloverSound);
    m_mousedownSound.setBuffer(s_mouseDownSound);
    m_mouseClickSound.setBuffer(s_mouseCLickSound);    
}


/// <summary>
/// draw button text on top of background
/// </summary>
/// <param name="t_window"></param>
void MenuItem::render(sf::RenderWindow& t_window)
{
    t_window.draw(m_button);
    t_window.draw(m_text);
}


/// <summary>
/// due rollover effect
/// </summary>
/// <param name="t_deltatime"></param>
/// <param name="t_window"></param>
void MenuItem::update(sf::Time t_deltatime, sf::RenderWindow& t_window)
{
    sf::Vector2i mouse;
    sf::Vector2f mousef;
    mouse = sf::Mouse::getPosition(t_window);
    mousef.x = static_cast<float>(mouse.x);
    mousef.y = static_cast<float>(mouse.y);
    if (m_area.contains(mousef))
    {
        if (!m_pressed)
        {
            m_text.setFillColor(sf::Color::Yellow);
            if (!m_highlighted) // only start sound once
            {
                m_mouseOverSound.play();
            }
            m_highlighted = true;        
        }
    }
    else
    { // outside button area
        m_text.setFillColor(sf::Color::Black);
        m_text.setCharacterSize(25);
        m_highlighted = false;
        m_pressed = false;
    }

}


/// <summary>
/// do button press and release to fire
/// </summary>
/// <param name="t_event"></param>
/// <returns>true if menu item activated</returns>
bool MenuItem::processInput(sf::Event t_event)
{
    sf::Vector2f mousef;

    mousef.x = static_cast<float>(t_event.mouseButton.x);
    mousef.y = static_cast<float>(t_event.mouseButton.y);

    if (sf::Event::MouseButtonPressed == t_event.type)
    {  
        if (m_area.contains(mousef))
        {
            m_pressed = true;
            m_text.setCharacterSize(23);
            m_mousedownSound.play();
        }
    }
    if (sf::Event::MouseButtonReleased == t_event.type && m_pressed)
    {
        if (m_area.contains(mousef))
        {      
            m_text.setCharacterSize(25);     
            m_text.setFillColor(sf::Color::Red);
            m_mouseClickSound.play();
            return true;
        }
    }
   




    return false;
}


/// <summary>
/// static method to load assets shared between all menu items
/// </summary>
void MenuItem::loadAssets()
{
    if (!s_buttonTexture.loadFromFile("ASSETS\\IMAGES\\button.png"))
    {
        std::cout << "problem button image" << std::endl;
    }
    if (!s_rolloverSound.loadFromFile("ASSETS\\AUDIO\\switch12.wav"))
    {
        std::cout << "problem button press" << std::endl;
    }
    if (!s_mouseDownSound.loadFromFile("ASSETS\\AUDIO\\rollover1.wav"))
    {
        std::cout << "problem button press" << std::endl;
    }
    if (!s_mouseCLickSound.loadFromFile("ASSETS\\AUDIO\\switch5.wav"))
    {
        std::cout << "problem button press" << std::endl;
    }
}
