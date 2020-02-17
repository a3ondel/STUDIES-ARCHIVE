#include "SelectMenu.h"
constexpr int MENUDIV = 2; // --vertical padding


SelectMenu::~SelectMenu()
{
	delete seletct;
	delete seletct_buffer;
	delete music;
}

SelectMenu::SelectMenu(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
	sf::Vector2f position_, sf::Color color_, const std::string& image_, const std::vector<std::string>& text_) :Menu(width_, hight_, window_, font_, position_, color_, image_, text_)
	, last_option(0),music(nullptr),seletct(nullptr),seletct_buffer(nullptr)
{
	for (int i = 0; i < n; i++)
	{
		//--------------------------\/adding empty options
		Options.push_back(0);
		TextOptions.push_back({});
		TextOptions[i].push_back("");
	}
}

SelectMenu::SelectMenu(const SelectMenu&tmp):SelectMenu(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,tmp.Box.getPosition())
{}

void SelectMenu::AddOptions(const unsigned int& i_element, std::vector<std::string> options_)
{
	TextOptions[i_element] = options_;
}

void SelectMenu::SetSelectedColor(const sf::Color& color_)
{
	SELECTED = color_;
}
void SelectMenu::mainmenu(const bool selection_, const  int starts)
{
	Running = true;
	if (music)
	{
		music->setLoop(1);
		music->play();

	}


	//SetTextColor(UNSELECTED);
	SetTextColor(starts, n - 1, UNSELECTED);

	SetTextColor(starts | last_option, SELECTED);

	int i = last_option;
	if (starts != 0)
		i = starts;
	while (Window->isOpen() && Running)
	{
		if (music)
			if (Audio_e)
			{
				if (music->getPlayingOffset() == sf::Time::Zero)
					music->play();
			}
			else music->stop();


		/*Box.rotate(i);
		Elements[i%6].rotate(i/2);*/

		sf::Event ev;
		while (Window->pollEvent(ev))
			if (ev.type == sf::Event::Closed)
				Window->close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{


			last_option = i;
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
			
			quit();

		}
		if (selection_)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (i + 1 < n)
				{
					if (seletct&&Music_e)seletct->play();
					SetTextColor(i, UNSELECTED);
					i++;
					SetTextColor(i, SELECTED);
				}
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down));

			}
			else

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					
					if (i - 1 >= starts)
					{
						if (seletct && Music_e)seletct->play();
						SetTextColor(i, UNSELECTED);
						i--;
						SetTextColor(i, SELECTED);
					}
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up));


				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					if (Options[i] - 1 >= 0)
					{
						Options[i]--;
						if (seletct && Music_e)seletct->play();
					}
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left));

				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					if (Options[i] + 1 < TextOptions[i].size())
					{
						Options[i]++;
						if (seletct && Music_e)seletct->play();
					}

					while (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

				}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				last_option = i;
				Elements[i].setFillColor(sf::Color::Yellow);
				if (seletct && Music_e)seletct->play();
				while (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
				
				Selected_Option(i);
			}
			else
				Elements[i].setFillColor(sf::Color::Red);
		}
		print(false);
	}

}

void SelectMenu::print(const bool& clear)
{
	if (clear)
		Window->clear();

	Window->draw(Box);

	std::string orginal = "";
	sf::Vector2f tmp;

	for (int i = 0; i < n; i++)
	{
		//if (Options[i] >= 0) no need of it bc of constructor, seting deafult value as 0 and Textoptions are filled with "" - empty strings
		tmp = Elements[i].getPosition();
		orginal = Elements[i].getString();

		Elements[i].setString(Elements[i].getString() + TextOptions[i][Options[i]]);
		Elements[i].setPosition(Width / 2 - Elements[i].getGlobalBounds().width / 2 + Box.getPosition().x, tmp.y);

		Window->draw(Elements[i]);
		Elements[i].setPosition(tmp);
		Elements[i].setString(orginal);
	}
	Window->display();
}

void SelectMenu::SetunSelectedColor(const sf::Color& color_)
{
	UNSELECTED = color_;
}

void SelectMenu::Set_Settings(bool buul, bool buulbuul, bool buulbuulbuuul)
{
	Audio_e = buul;
	Music_e = buulbuul;
	God_e = buulbuulbuuul;
}
