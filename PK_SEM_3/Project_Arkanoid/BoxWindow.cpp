#include "BoxWindow.h"

BoxWindow::BoxWindow(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_, sf::Vector2f position_, const std::string& image_, sf::Color color_)
	:Width(width_), Hight(hight_), Window(window_), font(font_), Running(true)
{
	Box.setSize({ width_,hight_ }); //seting box
	Box.setPosition(position_);

	if (image_ != "")
	{
		texture = new sf::Texture;
		texture->loadFromFile(image_);
		Box.setTexture(texture);
	}
	else
	{
		texture = nullptr;
		Box.setFillColor(color_);
	}
}

BoxWindow::BoxWindow(const BoxWindow& tmp) :BoxWindow(tmp.Width, tmp.Hight, tmp.Window, tmp.font, tmp.Box.getPosition(),"",tmp.Box.getFillColor())
{
}

BoxWindow::~BoxWindow()
{
	delete texture;
}

void BoxWindow::SetBGColor(const sf::Color& color_)
{
	Box.setFillColor(color_);
}

void BoxWindow::quit()
{
	Running = false;
}


