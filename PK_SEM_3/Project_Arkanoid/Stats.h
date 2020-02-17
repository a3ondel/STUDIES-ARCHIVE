#pragma once
#include "Info.h"


class Stats :
	public Info
{
	sf::Time TimePlayed;
	int Highscore;

	bool loadFromFile(const std::string &file_name="stats.ark");
	void print(const bool& clear) override;
public:
	Stats(const float& width_, const float& hight_, sf::RenderWindow* window_,
		sf::Font* font_, sf::Vector2f position_ = { 0,0 }, sf::Color color_ = sf::Color::Color(0, 0, 0, 0), 
		const std::string& image_="",std::vector<std::string> text_ = { "High Score: ","Time played: " }
		);
	Stats(const Stats&);
	void save_stats(const std::string& file_name="stats.ark");
	void addstats(sf::Vector2f);
};

