#include "Game.h"

constexpr float PI_ = 3.141592;
constexpr float GameSpeed = 1;

Game::Game(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
	sf::Vector2f position_, bool Music_, bool Audio_, bool GodMod_, int start_lives_, const std::string& image_, sf::Color color_)
	:BoxWindow(width_, hight_, window_, font_, position_, image_, color_), Music(Music_), AudioEffects(Audio_), GodMod(GodMod_), Lifes(start_lives_),
	Score(0), ball(Box.getSize(), 10), paddle({ 64,16 }, Box.getSize()), sd_collision(nullptr)
{
	//------------------------textures loading
	tex.loadFromFile("img\\grid.png");

	Box.setTexture(&tex);

	for (int i = 0; i < 4; i++)
	{
		sf::Texture tmp;
		block_tex.push_back(tmp);
	}

	block_tex[0].loadFromFile("img\\block.png");
	block_tex[1].loadFromFile("img\\block1.png");
	block_tex[2].loadFromFile("img\\block2.png");
	block_tex[3].loadFromFile("img\\block3.png");

	heart_tex.loadFromFile("img\\heart.png");
	
	eff2_tex.loadFromFile("img\\speed.png");
	eff3_tex.loadFromFile("img\\resize.png");
	heart.setTexture(&heart_tex);

	effect0.setSize({ Width,Hight });
	
	effect1.setSize({ 24,24 });
	effect1.setPosition(-2000, 0);
	effect1.setTexture(&heart_tex);

	effect2.setSize({ 30,30 });
	effect2.setPosition(-2000, 0);
	effect2.setTexture(&eff2_tex);

	effect3.setSize({ 40,40 });
	effect3.setPosition(-2000, 0);
	effect3.setTexture(&eff3_tex);

	heart.setSize({ 32,32 });
	heart.setPosition(0, 10);
	//------------------------- audio loading


	if (Music)
	{
		sd_music.openFromFile("audio\\background.ogg");
		sd_music.setLoop(1);
		sd_music.play();
	}
	
	if (AudioEffects)
	{
		collision_bf.loadFromFile("audio\\collision.ogg");
		sd_collision = new sf::Sound;
		sd_collision->setBuffer(collision_bf);
	}

	//--------------------------building map
	for (int i = 0; i < 9; i++)
	{
		//building lvl
			//points, lives
		Block tmp(30, 3, { static_cast<float>(25 + i * 128 + i * 10),static_cast<float>(120) }//, { static_cast<float>( 1280),static_cast<float>(120) }
		);

		Blocks.push_back(tmp);
	}

	for (auto &x : Blocks) // loading blocks 
		x.setTexture(&block_tex[0]);
	
	//-----------------------------others
	if (GodMod)
		paddle.setSize({ Width,paddle.getSize().y });
	paddle.setstartposition();
}

Game::Game(const Game&tmp):Game(tmp.Box.getSize().x,tmp.Box.getSize().y,tmp.Window,tmp.font,{0,0},tmp.Music,tmp.AudioEffects,tmp.GodMod,tmp.Lifes){}

Game::~Game()
{
	delete sd_collision;
}

sf::Vector2f Game::run()
{
	srand(time(NULL));
	int i_effect = rand() % 4;
	sf::RectangleShape* curr_effect = geteffect(i_effect);

	Running = 1;
	globalclock.restart();

	PauseMenu pm(Width / 2, Hight / 2, Window, font, { Width / 4,Hight / 4 }, sf::Color::White);
	pm.set_last_opened(&Running);

	while (Lifes > 0 && Window->isOpen() && Running)
	{
		effect_controller(i_effect, curr_effect);
		if (Blocks.size() <= 0)
			break;

		sf::Event ev;
		while (Window->pollEvent(ev))
			if (ev.type == sf::Event::Closed)
				Window->close();

		ball.Dupdate(Width, Hight, 0, 0, sd_collision);

		keyconntroler(&pm);

		if (ball.getPosition().y - 8 > paddle.getPosition().y)
			underpaddle();

		blocks_collision(curr_effect);
		ball.move(ball.Dx, ball.Dy);
		drawall();
	}
	sd_music.setLoop(0);
	sd_music.stop();


	if (GodMod)
		gm();
	else
	{
		Info Texbox(Width, Hight / 5, Window, font, { 0,Hight / 2 - Hight / 10 }, sf::Color::Cyan, "", { "YOUR SCORE: " + std::to_string(Score) });
		Texbox.mainmenu(sf::seconds(2));
	}
	return { static_cast<float>(Score),globalclock.getElapsedTime().asSeconds() };
}

void Game::drawall()
{
	Window->draw(Box);
	for (auto& block : Blocks)
		Window->draw(block);

	Window->draw(ball);
	Window->draw(paddle);

	heart.setPosition(0, 10);
	for (int i = 0; i < Lifes; i++)
	{
		heart.move(static_cast<float>(heart.getSize().x * 5 / 4), 0);
		Window->draw(heart);
	}
	Window->draw(effect1);
	Window->draw(effect2);
	Window->draw(effect3);
	Window->display();

}

void Game::blocks_collision(sf::RectangleShape* effect)
{


	int block_to_delete = -1;
	float tmpv = ball.getRadius() / sqrt(2) * 3;
	sf::FloatRect tmpball(ball.getPosition().x - tmpv / 2, ball.getPosition().y - tmpv / 2, tmpv, tmpv);

	auto x = &tmpball;
	for (int i = 0; i < Blocks.size(); i++)
	{
		if (tmpball.intersects(Blocks[i].getGlobalBounds()))
		{
			ball.collision({ 1,-1 });
			Score += Blocks[i].getpoints();
			if (sd_collision)sd_collision->play();

			if (Blocks[i].loselife())
				block_to_delete = i;
			else
				Blocks[i].setTexture(&block_tex[Blocks[i].getdmg()]);
			//Blocks[i].setFillColor(sf::Color::Color(255, 20, 208, 255));
			break;
		}
	}
	if (block_to_delete >= 0)
	{
		if (effect && effect->getPosition().x < 0)
			effect->setPosition(static_cast<float>(Blocks[block_to_delete].getPosition().x + Blocks[block_to_delete].getGlobalBounds().width / 2),
				Blocks[block_to_delete].getPosition().y + 10);
		Blocks.erase(Blocks.begin() + block_to_delete);

	}
}

void Game::underpaddle()
{
	Lifes--;
	sf::sleep(sf::milliseconds(200));
	ball.setstartposition({ Width,Hight });
	paddle.setstartposition();
	sf::sleep(sf::milliseconds(1200));

}

void Game::gm()
{
	sf::Clock tmp;
	tmp.restart();
	sd_music.openFromFile("audio\\win.ogg");
	sd_music.play();

	while (tmp.getElapsedTime().asSeconds() < 6 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); //quick escape

	sd_music.stop();

	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));

}

void Game::activateEf(int& i_effect, sf::RectangleShape* curr_effect)
{
	if (curr_effect && checkcollison(paddle.getGlobalBounds(), curr_effect->getGlobalBounds()))
	{
		std::cout << i_effect;
		curr_effect->setPosition(-2000, 0);

		switch (i_effect)
		{
		case 0: Lifes++;
			break;

		case 1: Lifes++;
			break;

		case 2: paddle.setSpeed(paddle.getSpeed() * 3/ 2); 
				paddle.setFillColor(sf::Color::Color(40, 125, 125, 255));
				speedtimer.restart();
			break;

		case 3: paddle.setSize({ static_cast<float>(paddle.getSize().x * 2), 10 });
				resizetimer.restart();
			break;

		default:
			break;
		}//activate effect on paddle or add life
		
		i_effect = rand() % 7; //50% chance to eny effect
	}
}

sf::RectangleShape* Game::geteffect(int i)
{
	switch (i)
	{
	case 0:		return &effect1;
		break;
	case 1:		return &effect1;
		break;
	case 2:		return &effect2;
		break;
	case 3:		return &effect3;
		break;
	default:	return &effect0;
		break;
	}

	return nullptr;
}

void Game::effect_controller(int& i_effect, sf::RectangleShape*& curr_effect)
{
	if (curr_effect && curr_effect->getPosition().y > 720)
		curr_effect->setPosition(-100, 0);

	if (curr_effect && curr_effect->getPosition().x > 0)
		curr_effect->move(0, 14);

	activateEf(i_effect, curr_effect);
	curr_effect = geteffect(i_effect);

	if (!GodMod && resizetimer.getElapsedTime().asSeconds() > 8)
		paddle.setSize({ 64,16 });

	if (!GodMod && speedtimer.getElapsedTime().asSeconds() > 8)
	{
		paddle.setSpeed(1.f);
		paddle.setFillColor(sf::Color::Color(255, 255, 255, 255));
	}
}

void Game::keyconntroler(PauseMenu* pm)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
		pm->mainmenu();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		ball.Dupdate(Width, Hight, 2, -1, paddle.getGlobalBounds(), sd_collision);
		paddle.move_left(GodMod);
	}
	else
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			ball.Dupdate(Width, Hight, 2, -1, paddle.getGlobalBounds(), sd_collision);
			paddle.move_right(GodMod);
		}
		else
			ball.Dupdate(Width, Hight, 1, -1, paddle.getGlobalBounds(), sd_collision);
}

bool Game::checkcollison(sf::FloatRect object1, sf::FloatRect object2)
{
	return object1.intersects(object2);
}