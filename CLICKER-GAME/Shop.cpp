#include "Shop.h"


shop::shop(tgui::Gui& gui) : gui(gui), ClickDmgShop(gui)
{
    panel = tgui::Panel::create({ "100%", "100%" });
    panel->getRenderer()->setBackgroundColor(tgui::Color{ 100, 100, 100, 150 });
    panel->setVisible(false);
    gui.add(panel);
}

void shop::AllButtons()
{
    ClickDmg();
    BackGroundButton();
    Equipment();
    Pet();
    Artifact();
}

void shop::ClickDmg()
{
    
    auto ClickDmgBtn = tgui::Button::create("ClickDmg");
    ClickDmgBtn->setPosition(10, 6);
    ClickDmgBtn->setSize(100, 40);
    ClickDmgBtn->onClick([ClickDmgBtn,this]()
        {
            std::cout << "ClickDmg button clicked!\n";
            ClickDmgBtn->setTextSize(20);
            isopenClickDmgShop = !isopenClickDmgShop;
            if (isopenClickDmgShop) {
                this->ClickDmgShop.open();
            }
            else {
                this->ClickDmgShop.close();
            }
            this->ClickDmgShop.items();
            
        });

    panel->add(ClickDmgBtn);
}

void shop::BackGroundButton()
{
    auto shopBtn = tgui::Button::create("BackGround");
    shopBtn->setSize(100, 40);
    shopBtn->setPosition(110, 6);
    panel->add(shopBtn);
}

void shop::Equipment()
{
    auto EquipmentBtn = tgui::Button::create("Equipment");
    EquipmentBtn->setSize(100, 40);
    EquipmentBtn->setPosition(210, 6);
    panel->add(EquipmentBtn);
}

void shop::Pet()
{
    auto PetBtn = tgui::Button::create("Pet");
    PetBtn->setSize(100, 40);
    PetBtn->setPosition(310, 6);
    panel->add(PetBtn);
}

void shop::Artifact()
{
    auto ArtifactBtn = tgui::Button::create("Artifact");
    ArtifactBtn->setSize(100, 40);
    ArtifactBtn->setPosition(410, 6);
    panel->add(ArtifactBtn);
}

void shop::show()
{
    panel->setVisible(true);
}

void shop::hide()
{
    panel->setVisible(false);
}
