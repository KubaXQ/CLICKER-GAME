#pragma once
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "ClickDmgShop.h"

class shop
{
public:
    explicit shop(tgui::Gui& gui, float& multiplier, float& money, std::map<int, bool>& itemBought);
    void AllButtons();
    void ClickDmg();
    void BackGroundButton();
    void Equipment();
    void Pet();
    void Artifact();
    void show();
    void hide();
    float& multiplier;
    float& money;
    std::map<int, bool>& itemBought;
    tgui::Gui& gui;
    tgui::Panel::Ptr panel;
    std::unique_ptr<ClickDmgShop> ClickDmgShop;
    bool isopenClickDmgShop = false;
};
