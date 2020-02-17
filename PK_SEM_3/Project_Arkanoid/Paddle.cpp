#include "Paddle.h"

constexpr float default_p_move = 10;

void Paddle::move_left(bool godmode)
{
	if (!godmode)
	{
		if (getPosition().x - default_p_move < 0)
			setPosition(0, getPosition().y);
		else
			move({ -default_p_move * Speed, 0 });
	}
	else
		move({ -2 * default_p_move * Speed,0 });
}

void Paddle::move_right(bool godmode)
{
	if (!godmode)
	{
		if (getPosition().x + default_p_move + getGlobalBounds().width > Border.x)
			setPosition(Border.x - getGlobalBounds().width, getPosition().y);
		else
			move({ default_p_move * Speed, 0 });
	}
	else
		move({ 2 * default_p_move * Speed,0 });

}

sf::Vector2f Paddle::getstartposition()
{

	return { Border.x / 2 - getSize().x, Border.y - 2 * getSize().y };

}

void Paddle::setstartposition()
{
	setPosition(getstartposition());
}

float Paddle::getSpeed()
{
	return Speed;
}

void Paddle::setSpeed(float sp)
{
	Speed = sp;
}

Paddle::Paddle(sf::Vector2f size_, sf::Vector2f border_) : Border(border_), Speed(1), Size(1)
{
	setSize(size_);

	setPosition(getstartposition());
	setScale(2, 1);
	tex.loadFromFile("img\\paddle.png");
	setTexture(&tex);
}

Paddle::Paddle(const Paddle& tmp) :Paddle({tmp.getSize().x,tmp.getSize().y},tmp.Border){}
