#pragma once
#include "Info.h"
class Credits :
	public Info
{
	
public:
	Credits(const float& width_, const float& hight_, sf::RenderWindow* window_,
		sf::Font* font_, sf::Vector2f position_ = { 0,0 }, sf::Color color_ = sf::Color::Color(0, 0, 0, 0),  const std::string& image_="", 
		std::vector<std::string> text_ = {"Arkanoid Game created by Adam Trznadel",
		"for semestral project of Computer Programming","version 1.0","created in 2019/2020" });

	Credits(const Credits&);
};

