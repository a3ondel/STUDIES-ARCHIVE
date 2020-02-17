#include "Ball.h"
#include <cmath>


constexpr float Starting_Ballspeed = 8;
constexpr float Default_b_move = 8;
constexpr float MAXD = 65;

void Ball::collision(sf::Vector2f Ds)
{

	Dx *= Ds.x;
	Dy *= Ds.y;

}

Ball::Ball(sf::Vector2f border, float radius_) :Dx(0), Dy(0)
{

	tex.loadFromFile("img\\ball.png");
	setRadius(radius_);
	setOrigin(radius_, radius_);
	setstartposition(border);
	setTexture(&tex);

}

Ball::Ball(const Ball& tmp) :Ball({300,300},tmp.getRadius())
{
}

bool Ball::Dupdate(float Width, float Hight, float nDx, float nDy, sf::Sound* coll)
{
	bool ifso = false;
	if (getPosition().x >= Width || getPosition().x - Default_b_move < 0)
	{

		collision({ -1,1 });
		if (coll)coll->play();
		ifso = true;
	}

	if (getPosition().y >= Hight || getPosition().y - Default_b_move < 0)
	{
		collision({ 1,-1 });
		if (coll)coll->play();
		ifso = true;
	}

	return ifso;
}

bool Ball::Dupdate(float Width, float Hight, float nDx, float nDy, sf::FloatRect object, sf::Sound* coll)
{
	if (getGlobalBounds().intersects(object))
	{
		if (Dx == 0)
			Dx = -1;

		if (fabs(Dx * nDx) < MAXD && fabs(Dy * nDy) < MAXD)
			collision({ nDx,nDy });
		else
			collision({ 1,-1 });

		if (coll)coll->play();

		return true;
	}
	return false;
}

sf::Vector2f Ball::getstartposition(sf::Vector2f border)
{
	return { border.x / 2 - 10,5 * border.y / 8 };
}

void Ball::setstartposition(sf::Vector2f border)
{
	setPosition(getstartposition(border));
	Dx = 0;
	Dy = Starting_Ballspeed;
}
