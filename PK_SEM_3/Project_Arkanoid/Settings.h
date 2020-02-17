#pragma once
#include "SelectMenu.h"

class Settings :
	public SelectMenu
{

	bool Music;
	bool AudioEffects;
	bool GodMode;

	void updatesetings();
	bool loadfromfile(const std::string file_name = "settings.ark");

	void Selected_Option(const unsigned int& i_option) override;
	void quit() override;

public:
	Settings(const float& width_, const float& hight_, sf::RenderWindow* window_,
		sf::Font* font_, sf::Vector2f position_ = { 0,0 }, sf::Color color_ = sf::Color::Color(0, 0, 0, 0), const std::string& image_ = "",
		std::vector<std::string> text_ = { "Music: ","Audio Effects: ","GodMode: " });

	Settings(const Settings&);
	void save_settings(const std::string& file_name = "settings.ark");
	bool getAudio();
	bool getMusic();
	bool getGod();

};

