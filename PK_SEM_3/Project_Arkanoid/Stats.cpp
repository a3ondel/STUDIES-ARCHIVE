#include "Stats.h"
#include <fstream>

bool Stats::loadFromFile(const std::string& file_name)
{
	std::ifstream file(file_name);

	if (file)
	{
		float tmp_sec;
		file >> tmp_sec;
		TimePlayed = sf::seconds(tmp_sec);
		file >> tmp_sec;
		Highscore = tmp_sec;

		file.close();
		if (TimePlayed.asSeconds() < 0 || Highscore < 0)
		{
			TimePlayed = sf::Time::Zero;
			Highscore = 0;
			return true;
		}
		return false;
	}

	return true;
}

Stats::Stats(const float& width_, const float& hight_, sf::RenderWindow* window_,
	sf::Font* font_, sf::Vector2f position_, sf::Color color_, const std::string& image_, std::vector<std::string> text_) :
	Info(width_, hight_, window_, font_, position_, color_, image_, text_)
{

	loadFromFile();

	Elements[0].setString("High score: " + std::to_string(Highscore));

	Elements[1].setString("Time played: " + std::to_string(static_cast<int>(TimePlayed.asSeconds() / 60)) + " minutes ");
}

Stats::Stats(const Stats&tmp ):Stats(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition()){}

void Stats::save_stats(const std::string& file_name)
{
	std::ofstream file(file_name);

	if (file)
	{
		file << TimePlayed.asSeconds() << " " << Highscore;
		file.close();
	}

}

void Stats::addstats(sf::Vector2f game_stats)
{

	if (game_stats.x > Highscore)
		Highscore = game_stats.x;
	TimePlayed = sf::seconds(TimePlayed.asSeconds() + game_stats.y);

}
void Stats::print(const bool& clear)
{
	if (clear)
		Window->clear();

	Window->draw(Box);
	Elements[0].setString("Highscore: " + std::to_string(Highscore));
	Elements[1].setString("Time Played: " + std::to_string(static_cast<int>((100 * TimePlayed.asSeconds()) / 6000)) + " minutes");

	for (int i = 0; i < n; i++)
	{

		Elements[i].setPosition(Width / 2 - Elements[i].getGlobalBounds().width / 2 + Box.getPosition().x, Hight / 4 + Box.getPosition().y + (2 * i) * Elements[i].getGlobalBounds().height);
		Window->draw(Elements[i]);

	}

	Window->display();
}
