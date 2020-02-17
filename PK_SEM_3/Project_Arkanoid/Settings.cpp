#include "Settings.h"
#include <vector>
#include <fstream>
void Settings::updatesetings()
{
	Music = Options[0];
	AudioEffects = Options[1];
	GodMode = Options[2];
}

bool Settings::loadfromfile(const std::string file_name)
{

	std::ifstream file(file_name);

	if (file)
	{
		file >> Music >> AudioEffects >> GodMode;

		file.close();

		return false;
	}


	return true;
}

void Settings::Selected_Option(const unsigned int& i_option)
{

	switch (i_option)
	{
	case 0: if (Options[0] == 0)
		Options[0]++;
		  else
		Options[0]--;
		break;
	case 1:if (Options[1] == 0)
		Options[1]++;
		  else
		Options[1]--;
		break;
	case 2:if (Options[2] == 0)
		Options[2]++;
		  else
		Options[2]--;
		break;
	default:
		break;
	}
}

void Settings::quit()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));

	updatesetings();
	Running = false;
}

Settings::Settings(const float& width_, const float& hight_, sf::RenderWindow* window_,
	sf::Font* font_, sf::Vector2f position_, sf::Color color_, const std::string& image_, std::vector<std::string> text_) :
	SelectMenu(width_, hight_, window_, font_, position_, color_, image_, text_)
{
	loadfromfile();

	if (text_.size() >= 3)
	{
		AddOptions(0, { "off","on" });
		AddOptions(1, { "off","on" });
		AddOptions(2, { "off","on" });

		Options[0] = Music;
		Options[1] = AudioEffects;
		Options[2] = GodMode;
	}
};

Settings::Settings(const Settings& tmp):Settings(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition()){}

void Settings::save_settings(const std::string& file_name)
{
	std::ofstream file(file_name);

	if (file)
	{
		std::cout << " ZAPISYWANKO USTAWIEN "; //TODELETE

		file << Music << " " << AudioEffects << " " << GodMode;
		file.close();
	}
}

bool Settings::getAudio()
{
	return AudioEffects;
}

bool Settings::getMusic()
{
	return Music;
}

bool Settings::getGod()
{
	return GodMode;
}
