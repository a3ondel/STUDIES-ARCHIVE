#pragma once
#include "Menu.h"
#include "PauseMenu.h"
class Info :public Menu
{
	virtual void print(const bool& clear);
	void quit()override;
public:

	void mainmenu(sf::Time time_=sf::seconds(3000));
	using Menu::Menu;
};

