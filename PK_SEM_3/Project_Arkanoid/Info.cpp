#include "Info.h"

void Info::mainmenu(sf::Time time_)
{
	Running = true;
	sf::Clock clock;
	clock.restart();

	while (Window->isOpen() && Running&&clock.getElapsedTime().asSeconds()<time_.asSeconds())
	{
		
		sf::Event ev;
		while (Window->pollEvent(ev))
			if (ev.type == sf::Event::Closed)
				Window->close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			quit();
			
			
		}
		print(false);
		
	}
}

void Info::print(const bool& clear) //drawing on screen all text elements
{
	if (clear)
		Window->clear();

	Window->draw(Box);

	for (int i = 0; i < n; i++)
	{
		Elements[i].setPosition(Width / 2 - Elements[i].getGlobalBounds().width / 2 + Box.getPosition().x, Hight/4 + Box.getPosition().y + (2*i)*Elements[i].getGlobalBounds().height);
		Window->draw(Elements[i]);	
	}

	Window->display();
}

void Info::quit()
{
	sf::sleep(sf::milliseconds(100));
	Running = false;
}
