#include "CoreMenu.h"
#include <fstream>


CoreMenu::CoreMenu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_, sf::Vector2f position_, sf::Color color_, const std::string& image_,
	const std::vector<std::string>& text_)
	: SelectMenu(width_, hight_, window_, font_, position_, color_, image_, text_),
	stats(width_, hight_, window_, font_, position_, sf::Color::Cyan, ""),
	settings(width_, hight_, window_, font_, position_, sf::Color::White, ""),
	credits(width_, hight_, window_, font_, position_, sf::Color::Color(246, 243, 85, 254), "")
{
	Set_Settings(settings.getMusic(), settings.getAudio(), settings.getGod());
	std::cout << " coremenu sie wlacza " << std::endl;
	SetCharSize(0, 80);
	SetTextColor(0, 0, sf::Color::Color(131, 7, 140, 255));
	music = new sf::Music;
	music->openFromFile("audio\\menu.ogg");
	seletct = new sf::Sound;
	seletct_buffer = new sf::SoundBuffer;

	seletct_buffer->loadFromFile("audio\\select.ogg");
	seletct->setBuffer(*seletct_buffer);

}

void CoreMenu::Selected_Option(const unsigned int& i)
{
	switch (i)
	{
		//lives - ammount of blocks
	case 2: {
			Game game(Width, Hight, Window, font, { 0,0 }, settings.getMusic(), settings.getAudio(),
			settings.getGod(), 3, "img\\coremenu.jpg");
			music->stop(); sf::Vector2f tmp = game.run();
			stats.addstats(tmp);
			}
		  break;

	case 3:settings.mainmenu();
			Set_Settings(settings.getMusic(), settings.getAudio(), settings.getGod());
		break;

	case 4:
		stats.mainmenu();

		break;

	case 5:credits.mainmenu();
		break;

	case 6: quit();
		break;

	default:
		break;
	}
}

CoreMenu::CoreMenu(const CoreMenu& tmp):CoreMenu(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition()){}

CoreMenu::~CoreMenu()
{
	stats.save_stats();
	settings.save_settings();
}


