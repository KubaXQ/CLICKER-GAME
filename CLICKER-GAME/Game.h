#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <string>
#include <iostream>
class Game
{
public:
	Game();
	void Running();
	void Events();
	void ClosingEvent(const sf::Event& ev);
	void ClickingEvent(const sf::Event& ev);
	void ShopClickEvent(const sf::Event& ev);
	void LoadingFont();
	void Parameters();
	void Displaying();
	void DisplayingMoney(int cash);
	void DisplayingShop();
	void ShopButton();
	int money = 0;
	bool isShopOpen = false;
	sf::RenderWindow window;
	sf::Font font;
	sf::RectangleShape shopbutton;
	tgui::Gui gui;
};
