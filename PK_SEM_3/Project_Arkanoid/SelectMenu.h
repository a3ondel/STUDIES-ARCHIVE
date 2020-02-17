#pragma once
#include "Menu.h"
class SelectMenu :
	public Menu
{
protected:

	int last_option;
	sf::Color SELECTED = sf::Color::Red;
	bool Audio_e;
	bool Music_e;
	bool God_e;
	sf::Color UNSELECTED = sf::Color::Black;

	sf::Music* music;
	sf::Sound* seletct;
	sf::SoundBuffer* seletct_buffer;
	std::vector <std::vector<std::string>> TextOptions; //options to print
	std::vector <int> Options; //choosen option

	void print(const bool& clear);

	virtual void Selected_Option(const unsigned int&) = 0;

public:
	~SelectMenu();
	SelectMenu(const float& width_, const float& hight_, sf::RenderWindow* window_,
		sf::Font* font_, sf::Vector2f position_ = { 0,0 }, sf::Color color_ = sf::Color::Color(0, 0, 0, 0), const std::string& image_ = "",
		const std::vector<std::string>& text_ = { "EXIT" });
	SelectMenu(const SelectMenu&);

	void mainmenu(const bool selection_ = true, const  int starts = 0);
	void AddOptions(const unsigned int& i_element, std::vector<std::string> options_);

	void SetSelectedColor(const sf::Color& color_);
	void SetunSelectedColor(const sf::Color& color_);


	void Set_Settings(bool, bool, bool);

};

