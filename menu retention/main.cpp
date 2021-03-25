/// <summary>
/// simple game loop for SFML[2.5.1]
/// 
/// @author Peter Lowe
/// @date May 2019
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "Game.h"



/// <summary>
/// static variable really global variables
/// declared here
/// </summary>
GameMode Game::s_currentMode = GameMode::Red;
sf::Font Game::s_font;
sf::Texture MenuItem::s_buttonTexture;
sf::SoundBuffer MenuItem::s_rolloverSound;
sf::SoundBuffer MenuItem::s_mouseDownSound;
sf::SoundBuffer MenuItem::s_mouseCLickSound;



/// <summary>
/// main enrtry point
/// </summary>
/// <returns>success or failure</returns>
int main()
{
	MenuItem::loadAssets();
	Game game;
	game.run();

	return 1; // success
}