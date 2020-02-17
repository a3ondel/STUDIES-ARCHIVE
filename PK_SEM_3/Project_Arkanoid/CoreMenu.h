#pragma once
#include "SelectMenu.h"
#include "Info.h"

#include "Credits.h"
#include "Settings.h"
#include "PauseMenu.h" //prob wont be used
#include "Stats.h"
#include "Game.h"

extern const float GameSpeed;
extern const float Starting_Ballspeed;
extern const float default_p_move;
extern const float Default_b_move;

class CoreMenu :public SelectMenu
{
	
	Stats stats;
	Settings settings;
	Credits credits;

	//void quit()override;
	void Selected_Option(const unsigned int&);
	
public:

	CoreMenu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
		sf::Vector2f position_, sf::Color color_=sf::Color::Green, const std::string& image_ = "",
		const std::vector<std::string>& text_= { "Arkanoid GAME","","PLAY","SETTINGS","STATS","CREDITS","QUIT" });

	CoreMenu(const CoreMenu&);//copy 
	~CoreMenu();

};

