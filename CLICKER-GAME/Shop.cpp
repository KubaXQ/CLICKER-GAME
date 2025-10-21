#include "Shop.h"

//constructor for shop
shop::shop(tgui::Gui& gui, float& multiplier, float& money, std::map<int, bool>& itemBought) : gui(gui), multiplier(multiplier), money(money),itemBought(itemBought)
{
    panel = tgui::Panel::create({ "100%", "100%" });
    panel->getRenderer()->setBackgroundColor(tgui::Color{ 100, 100, 100, 150 });
    panel->setVisible(false);
    gui.add(panel);

    ClickDmgShop = std::make_unique<class ClickDmgShop>(panel,multiplier,money,itemBought);
}


void shop::AllButtons()
{
    ClickDmg();
    BackGroundButton();
    Equipment();
    Pet();
    Artifact();
}

//clickdmg button that shows clickdmg items or hide them
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
            }
            else
            {
                ClickDmgShop->close();
            }
        });

    panel->add(ClickDmgBtn);
}

//BackGroundButton button that shows BackGroundButton items or hide them
void shop::BackGroundButton()
{
    auto shopBtn = tgui::Button::create("BackGround");
    shopBtn->setSize(100, 40);
    shopBtn->setPosition(110, 6);
    panel->add(shopBtn);
}

//Equipment button that shows Equipment items or hide them
void shop::Equipment()
{
    auto EquipmentBtn = tgui::Button::create("Equipment");
    EquipmentBtn->setSize(100, 40);
    EquipmentBtn->setPosition(210, 6);
    panel->add(EquipmentBtn);
}

//Pet button that shows Pet items or hide them
void shop::Pet()
{
    auto PetBtn = tgui::Button::create("Pet");
    PetBtn->setSize(100, 40);
    PetBtn->setPosition(310, 6);
    panel->add(PetBtn);
}

//Artifact button that shows Artifact items or hide them
void shop::Artifact()
{
    auto ArtifactBtn = tgui::Button::create("Artifact");
    ArtifactBtn->setSize(100, 40);
    ArtifactBtn->setPosition(410, 6);
    panel->add(ArtifactBtn);
}

//set panel to visible
void shop::show()
{
    panel->setVisible(true);
}

//set panel to unvisible
void shop::hide()
{
    panel->setVisible(false);
}
