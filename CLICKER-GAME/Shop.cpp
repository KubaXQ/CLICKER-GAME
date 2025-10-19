#include "Shop.h"

shop::shop(tgui::Gui& gui) : gui(gui)
{
    panel = tgui::Panel::create({ "100%", "100%" });
    panel->getRenderer()->setBackgroundColor(tgui::Color{ 100, 100, 100, 150 });
    panel->setVisible(false);
    gui.add(panel);

    ClickDmgShop = std::make_unique<class ClickDmgShop>(panel);
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

    ClickDmgBtn->onClick([this, ClickDmgBtn]()
        {
            std::cout << "ClickDmg button clicked!\n";
            isopenClickDmgShop = !isopenClickDmgShop;

            if (isopenClickDmgShop)
            {
                ClickDmgShop->open();
                ClickDmgShop->items();
            }
            else
            {
                ClickDmgShop->close();
            }
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
