#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Ball :public sf::CircleShape
{
	sf::Texture tex;
	
public:
	float Dx;
	float Dy;
	Ball(sf::Vector2f start_position,float radius_);
	Ball(const Ball&);
	void collision(sf::Vector2f Ds);

	bool Dupdate(float Width, float Hight, float nDx, float nDy,sf::Sound *coll);
	bool Dupdate(float Width, float Hight,  float nDx, float nDy,sf::FloatRect object, sf::Sound* coll);
	sf::Vector2f getstartposition(sf::Vector2f border);
	void setstartposition(sf::Vector2f border);
	
};

