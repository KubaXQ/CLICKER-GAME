#pragma once
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <string>
#include <iostream>
class shop
{
public:
	explicit shop(tgui::Gui& gui);
	void AllButtons();
	void ClickDmg();
	void BackGroundButton();
	void Equipment();
	void Pet();
	void Artifact();
	tgui::Gui& gui;
	
};
