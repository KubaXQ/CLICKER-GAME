#pragma once
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "ArtifactShop.h"
#include "BackGroundShop.h"
#include "ClickDmgShop.h"
#include "PetShop.h"
#include "EquipmentShop.h"
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
	void show();
	void hide();
	tgui::Gui& gui;
	tgui::Panel::Ptr panel;
	ClickDmgShop ClickDmgShop;
	
};
