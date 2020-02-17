#include "PauseMenu.h"



void PauseMenu::quit()
{
	Running = false;

}



void PauseMenu::set_last_opened(bool* is)
{
	last_opened = is;
}

void PauseMenu::Selected_Option(const unsigned int& i_option)
{

	switch (i_option)
	{
	case 0:  quit();
		break;
	case 1: if (last_opened)*last_opened = false; quit();
		break;
	default:
		break;
	}

}

PauseMenu::PauseMenu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_, sf::Vector2f position_, sf::Color color_, const std::string& image_,
	std::vector<std::string> text_) :
	SelectMenu(width_, hight_, window_, font_, position_, color_, image_, text_), last_opened(nullptr)
{


}

PauseMenu::PauseMenu(const PauseMenu& tmp):PauseMenu(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition()){}
