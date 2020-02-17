#include "Credits.h"


Credits::Credits(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_, sf::Vector2f position_, sf::Color color_, 
	const std::string& image_ ,std::vector<std::string> text_):
	Info(width_, hight_, window_, font_, position_, color_, image_,text_)
{
	SetTextColor(sf::Color::Black);
}

Credits::Credits(const Credits& tmp ):Credits(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition()){}
