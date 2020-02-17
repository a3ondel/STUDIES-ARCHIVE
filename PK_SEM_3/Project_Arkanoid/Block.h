#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class Block :public sf::RectangleShape
{
	int Points;
	int Lives;
	int dmg;
	sf::Texture* tex;
	
public:
	Block(int points_, int lives_, sf::Vector2f position, sf::Vector2f size_ = { 128,24 }, sf::Color color_ = sf::Color::Blue);
	Block(const Block&);
	int getpoints();
	bool loselife();
	int getdmg();

};

