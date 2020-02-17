#pragma once
#include "BoxWindow.h"
#include "Ball.h"
#include "Block.h"
#include "Paddle.h"
#include "PauseMenu.h"
#include "Info.h"
#include <string>
#include <random>


class Game :
	public BoxWindow
{
	bool Music;
	bool AudioEffects;
	bool GodMod;

	int Lifes;
	int Score;

	Ball ball;
	Paddle paddle;
	std::vector<Block> Blocks;

	//--------------------------------textures , hp and effects objects
	sf::Texture tex;
	std::vector<sf::Texture>block_tex;

	sf::RectangleShape heart;
	sf::Texture heart_tex;
	sf::Texture eff2_tex;
	sf::Texture eff3_tex;
	sf::RectangleShape effect0;
	sf::RectangleShape effect1;
	sf::RectangleShape effect2;
	sf::RectangleShape effect3;

	//-------------------------------Audio
	sf::Music sd_music;
	sf::SoundBuffer collision_bf;
	sf::Sound* sd_collision;

	//-------------------------------Timers
	sf::Clock globalclock; //counting time played
	sf::Clock resizetimer;
	sf::Clock speedtimer;


	bool checkcollison(sf::FloatRect object1, sf::FloatRect object2); //checking callisions of 2 floatrect objects, its used to chceck if effect object is colliding with paddle(could be used somewhere else)
	void blocks_collision(sf::RectangleShape* effect); //checking collisions of ball with blocks and if ball is colliding specific effect object will be moved to start falling of it
	void drawall(); //dawing all wanted to objects
	void underpaddle(); //reset positions of paddle and ball with small delay
	void gm();//godmode
	void activateEf(int&, sf::RectangleShape*);
	sf::RectangleShape* geteffect(int i);
	void effect_controller(int& i_efect, sf::RectangleShape*& curr_effect);
	void keyconntroler(PauseMenu* pm);

public:
	Game(const float& width_, const float& hight_, sf::RenderWindow* window_, sf::Font* font_,
		sf::Vector2f position_, bool Music, bool Audio_, bool GodMod_, int start_lives_, 
		const std::string& image_ = "", sf::Color color_ = sf::Color::White);
	Game(const Game&);
	~Game();

	sf::Vector2f run(); //game activator
};

