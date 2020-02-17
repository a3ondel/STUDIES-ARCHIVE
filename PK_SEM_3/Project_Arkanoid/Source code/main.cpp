// Project_Arkanoid 
// Author: Adam Trznadel
///---------------------
//
//
///---------------------

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include "Menu.h"

#include "Credits.h"
#include "PauseMenu.h"
#include "Settings.h"
#include "Stats.h"
#include "CoreMenu.h"
#include "Game.h"
#include <vector> 
#include <string> 



//ctrl + k + d cleanup
//alt+shift pisanie w wilu liniach

constexpr int W_ = 1280;
constexpr int H_ = 720;

int main()
{
	sf::RenderWindow windows(sf::VideoMode(W_, H_), "Arkanoid Game");
	sf::Font font;

	if (!font.loadFromFile("LemonMilk.otf"))
		return 67;
	
	windows.setFramerateLimit(60);
	
	
	CoreMenu coremenu(W_, H_, &windows, &font, { 0,0 }, sf::Color::Black, "img\\coremenu.jpg");
	coremenu.mainmenu(true,2);
	
	return 0;



	

}