#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
class BoxWindow
{
protected:

	bool Running;

	float Width;		//width of displaying box 
	float Hight;		//hight of displaying box
	sf::Texture *texture;
	sf::Font* font;
	sf::RectangleShape Box;		// (box is a rectangle - within menu)	
	sf::RenderWindow* Window;   //opened window
	
	virtual void quit();
	
public:
	BoxWindow(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
		sf::Vector2f position_, const std::string& image_ = "",sf::Color color_=sf::Color::White);
	BoxWindow(const BoxWindow&);
	~BoxWindow();

	void SetBGColor(const sf::Color& color_); 

};

