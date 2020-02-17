#include "Block.h"

Block::Block(int points_, int lives_, sf::Vector2f position, sf::Vector2f size_, sf::Color color_)
	:sf::RectangleShape(size_), Lives(lives_), Points(points_), dmg(0)
{
	setPosition(position);
	setFillColor(sf::Color::White);
}

Block::Block(const Block& tmp):Block(tmp.Points,tmp.Lives,tmp.getPosition(),tmp.getSize())
{
}

int Block::getpoints()
{
	return Points;
}

bool Block::loselife()
{
	Lives--;
	dmg++;
	if (Lives <= 0)
		return true;
	else
		return false;
}

int Block::getdmg()
{
	return dmg;
}

