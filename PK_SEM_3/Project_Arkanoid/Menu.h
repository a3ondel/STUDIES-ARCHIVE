#pragma once
#include "BoxWindow.h"



class Game;
class Settings;


class Menu : public BoxWindow
{
protected:

	int n;			//amount of elements
	//const unsigned int DELAY = 120;
	sf::Text* Elements;			//array of strings to display

public:

	Menu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
		sf::Vector2f position_, sf::Color color_, const std::string& image_ = "", const std::vector<std::string>& text_ = { "" });

	Menu(const Menu&);
	~Menu();

	void SetTextColor(const sf::Color& color_);
	bool SetTextColor(const unsigned int& i_element, const sf::Color& color_);
	bool SetTextColor(const int& from_, const int& to_, const sf::Color& color_);
	void SetCharSize(const unsigned int& size); //set char size to every text in class
	void SetCharSize(const unsigned int& i_element, const unsigned int& size_);//setchar to specific text


};


