#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Paddle :public sf::RectangleShape
{

	float Size;
	float Speed;

	sf::Vector2f Border;
	sf::Texture tex;

	sf::Time clock;

public:

	Paddle(sf::Vector2f size_, sf::Vector2f border_);
	Paddle(const Paddle&);
	sf::Vector2f getstartposition();
	void setstartposition();
	float getSpeed();
	void setSpeed(float sp);
	void move_left(bool godmode);
	void move_right(bool godmode);
};

