#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "shop.h"
#include <iomanip>
#include <unordered_map>
#include <fstream>
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
	void Displaying();
	void DisplayingMoney(float money);
	void DisplayingClickDmgItem();
	void ShopButton();
	void SaveGame();
	void LoadGame();
	float money = 20000;
	float multiplier = 1.0f;
	std::map<int, bool> itemBought;
	bool isShopOpen = false;
	tgui::Picture::Ptr ClickDmgPic;
	tgui::Panel::Ptr GamePanel;
	sf::RenderWindow window;
	sf::Font font;
	sf::RectangleShape shopbutton;
	tgui::Gui gui;
	shop shop;
};
