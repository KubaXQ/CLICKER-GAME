#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
class Game
{
public:
	Game();
	void Running();
	void Events();
	void ClosingEvent(const sf::Event& ev);
	void LoadingFont();
	void DisplayingMoney(int cash);
	void ClickingEvent(const sf::Event& ev);
	int money = 0;
	sf::RenderWindow window;
	sf::Font font;
};

