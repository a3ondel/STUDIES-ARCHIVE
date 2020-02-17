#pragma once
#include "SelectMenu.h"

class PauseMenu :public SelectMenu
{
	bool* last_opened;
	void Selected_Option(const unsigned int& i_option) override;
	void quit() override;

public:
	void set_last_opened(bool*);
	PauseMenu(const float& width_, const float& hight_, sf::RenderWindow* window_,
		sf::Font* font_, sf::Vector2f position_ = { 0,0 }, sf::Color color_ = sf::Color::Color(0, 0, 0, 0), const std::string& image_ = "", std::vector<std::string> text_ = { "RESUME","EXIT" });

	PauseMenu(const PauseMenu&);
};

