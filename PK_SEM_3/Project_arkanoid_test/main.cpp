// Project_Arkanoid 
// Author: Adam Trznadel

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include "clickableRect.h"
#include <random>
#include <string>
constexpr int W_ = 720 / 1.5;
constexpr int H_ = 1080 / 1.5;
int main()
{
	sf::RectangleShape shape({ W_,H_ });
	shape.setFillColor(sf::Color::White);



	sf::RectangleShape pasek({ W_,H_ / 10 });
	pasek.setFillColor(sf::Color::Color(34, 167, 240, 255));
	sf::RectangleShape xx({ 20,20 });
	xx.setFillColor(sf::Color::Red);

	//--------window
	sf::RenderWindow window(sf::VideoMode(W_, H_), "COUNTER");
	window.setFramerateLimit(60);


	sf::Font font;
	font.loadFromFile("arial.ttf");



	sf::Text head("Benzyna ", font, 30);
	head.setPosition({ 0
		//W_ / 2 -head.getGlobalBounds().width/2
		,10 });

	sf::Texture texpasek;
	if (!texpasek.loadFromFile("img\\border.png"))
		return 255;


	sf::CircleShape click(W_ / 10);
	click.setOrigin(W_ / 10, W_ / 10);
	click.setFillColor(sf::Color::Color(34, 167, 240, 255));
	click.setPosition({ W_ - click.getGlobalBounds().width - W_ / 15,H_ - click.getGlobalBounds().height - H_ / 25 });
	//click.setTextxure(&texpasek);
	xx.setOrigin(10, 10);
	xx.setPosition({ W_ / 2,H_ / 2 });
	int i = 0;
	while (window.isOpen())
	{
		
		i++;
		sf::Event eventy;

		//if (a.getGlobalBounds().intersects(myszka.getGlobalBounds()))
		

		xx.rotate((float)i);
		while (window.pollEvent(eventy))
		{
			if (eventy.type == sf::Event::Closed)
				window.close();
		}



		window.clear();
		window.draw(xx);
		window.display();


		

	}


	return 0;
}





















//sf::Music buffer;
//sf::Music buffer2;
//sf::Music buffer3;
//buffer.openFromFile("audio\\sample2.wav");
//buffer2.openFromFile("audio\\sample.wav");
//buffer3.openFromFile("audio\\sample.wav");
//
//sf::RenderWindow window(sf::VideoMode(W_, H_), "Project_Arkanoid");
////sf::CircleShape shape(15,12);
//sf::ConvexShape shape;
//shape.setPointCount(10);
//shape.setPoint(0, { 100,1 });
//shape.setPoint(1, { 1,3 });
//shape.setPoint(2, { 10,20 });
//shape.setPoint(3, { 77,14 });
//shape.setPoint(4, { 240,1 });
//shape.setPoint(5, { 100,1 });
//shape.setPoint(6, { 567,30 });
//shape.setPoint(7, { 76,19 });
//shape.setPoint(8, { 10,13 });
//shape.setPoint(9, { 10,12 });
//shape.setPosition(W_ / 2 - 100, H_ / 2 - 100);
//shape.setFillColor(sf::Color::Green);
//window.setFramerateLimit(40);
//buffer.play();
//float kat = 0;
//float cyk = 0;
//float cyk1 = 0;
//
//buffer.setLoop(1);
//buffer.setPitch(0.2);
//auto ss = buffer.getSampleRate();
//while (window.isOpen())
//{
//	if (kat > 300)
//	{
//
//		kat = 0;
//		cyk = 0;
//		cyk1 = 250;
//
//
//	}
//	else
//		if (kat > 100)
//		{
//			cyk1 = 0;
//
//		}
//		else
//			if (kat > 200)
//				cyk = 500;
//
//
//
//
//	kat += 0.5;
//	shape.setPosition({ 50 * cos(kat) - 50 * sin(kat) + cyk + 200,50 * cos(kat) + 50 * sin(kat) + 200 + cyk1 });
//	if (buffer.getPlayingOffset().asSeconds() > 0.5)
//	{
//		//buffer.play();
//		shape.setFillColor(sf::Color::Cyan);
//	}
//	else if (buffer.getPlayingOffset().asSeconds() > 0)
//	{
//		shape.setFillColor(sf::Color::Magenta);
//
//	}
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//	if (kat > 100)
//		shape.setFillColor(sf::Color::Blue);
//	window.clear();
//	window.draw(shape);
//	window.display();
//}