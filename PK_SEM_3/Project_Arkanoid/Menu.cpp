#include "Menu.h"

constexpr int MENUDIV = 2; // --vertical padding

Menu::Menu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
	sf::Vector2f position_, sf::Color color_, const std::string& image_, const std::vector<std::string>& text_)
	:BoxWindow(width_, hight_, window_, font_, position_, image_, color_), n(text_.size())
{
	std::cout << " tworzenie obieku: " << this << std::endl; //TODELETE

	Elements = new sf::Text[n]; //making dynamic array of texts

	for (int i = 0; i < text_.size(); i++)
	{
		Elements[i].setString(text_[i]); //seting array with strings
		Elements[i].setCharacterSize(30);
		Elements[i].setFont(*font_);
		Elements[i].setPosition(Width / 2 - Elements[i].getGlobalBounds().width / 2 + Box.getPosition().x, Hight * (i + 1) / (n + MENUDIV) + Box.getPosition().y + Elements[i].getGlobalBounds().height);
		Elements[i].setFillColor(sf::Color::Black);
		//--------------------------\/adding empty options
	}
}

Menu::Menu(const Menu& tmp) :Menu(tmp.Box.getSize().x, tmp.Box.getSize().y, tmp.Window, tmp.font, tmp.Box.getPosition(), tmp.Box.getFillColor(), "", {""}) {}

Menu::~Menu()
{
	std::cout << "usuwanko lokalizacja: " << this << std::endl; //TODELETE
	delete[] Elements;
}


void Menu::SetTextColor(const sf::Color& color_)
{
	for (int i = 0; i < n; i++)
		Elements[i].setFillColor(color_);
}
bool Menu::SetTextColor(const int& from_, const int& to_, const sf::Color& color_)
{
	if (from_ < 0 || to_ >= n)
		return true; // out off array

	for (int i = from_; i <= to_; i++)
		Elements[i].setFillColor(color_);

	return false;
}

bool Menu::SetTextColor(const unsigned int& i_element, const sf::Color& color_)
{
	if (i_element >= n) //if out of array
		return true;

	Elements[i_element].setFillColor(color_);

	return false; //all good
}

void Menu::SetCharSize(const unsigned int& size)
{
	for (int i = 0; i < n; i++)
	{
		Elements[i].setCharacterSize(size);
	}
}

void Menu::SetCharSize(const unsigned int& i_element, const unsigned int& size_)
{
	Elements[i_element].setCharacterSize(size_);
}








