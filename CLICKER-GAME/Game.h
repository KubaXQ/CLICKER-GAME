#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "shop.h"
#include <iomanip>
class Game
{
public:
	Game();
	void Running();
	void Events();
	void ClosingEvent(const sf::Event& ev);
	void ClickingEvent(const sf::Event& ev , float multiplier);
	void ShopClickEvent(const sf::Event& ev);
	void LoadingFont();
	void Displaying();
	void DisplayingMoney(float money);
	void ShopButton();
	float money = 0;
	float multiplier = 1;
	bool isShopOpen = false;
	sf::RenderWindow window;
	sf::Font font;
	sf::RectangleShape shopbutton;
	tgui::Gui gui;
	shop shop;
};
