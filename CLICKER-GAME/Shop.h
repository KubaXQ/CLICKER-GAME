#pragma once
#include <TGUI/TGUI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "ClickDmgShop.h"
#include "BaseShop.h"
#include "BackGroundShop.h"
#include "EquipmentShop.h"
#include "PetShop.h"
#include "ArtifactShop.h"



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
    std::unique_ptr<BackGroundShop> BackGroundShop;
    std::unique_ptr<EquipmentShop> EquipmentShop;
    std::unique_ptr<PetShop> PetShop;
    std::unique_ptr<ArtifactShop> ArtifactShop;

    bool isopenClickDmgShop = false;
    bool isopenBackGroundShop = false;
    bool isopenEquipmentShop = false;
    bool isopenPetShop = false;
    bool isopenArtifactShop = false;


};
