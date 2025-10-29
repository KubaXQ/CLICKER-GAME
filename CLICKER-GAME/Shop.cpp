#include "Shop.h"

//constructor for shop
shop::shop(tgui::Gui& gui, float& multiplier, float& money, std::map<int, bool>& itemBought) : gui(gui), multiplier(multiplier), money(money),itemBought(itemBought)
{
    panel = tgui::Panel::create({ "100%", "100%" });
    panel->getRenderer()->setBackgroundColor(tgui::Color{ 100, 100, 100, 150 });
    panel->setVisible(false);
    gui.add(panel);

    ClickDmgShop = std::make_unique<class ClickDmgShop>(panel,multiplier,money,itemBought);
    BackGroundShop = std::make_unique<class BackGroundShop>(panel, multiplier, money);
    EquipmentShop = std::make_unique<class EquipmentShop>(panel, multiplier, money);
    PetShop = std::make_unique<class PetShop>(panel, multiplier, money);
    ArtifactShop = std::make_unique<class ArtifactShop>(panel, multiplier, money);

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
                isopenBackGroundShop = false;
                isopenEquipmentShop = false;
                isopenPetShop = false;
                isopenArtifactShop = false;
                BackGroundShop->close();
                ArtifactShop->close();
                PetShop->close();
                EquipmentShop->close();
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
    auto BackGroundButton = tgui::Button::create("BackGround");
    BackGroundButton->setSize(100, 40);
    BackGroundButton->setPosition(110, 6);
    BackGroundButton->onClick([this, BackGroundButton]()
        {
            std::cout << "BackGroundButton button clicked!\n";
            isopenBackGroundShop = !isopenBackGroundShop;

            if (isopenBackGroundShop)
            {
                isopenClickDmgShop = false;
                isopenEquipmentShop = false;
                isopenPetShop = false;
                isopenArtifactShop = false;
                ClickDmgShop->close();
                ArtifactShop->close();
                PetShop->close();
                EquipmentShop->close();
                BackGroundShop->open();
            }
            else
            {
                BackGroundShop->close();
            }
        });



    panel->add(BackGroundButton);
}

//Equipment button that shows Equipment items or hide them
void shop::Equipment()
{
    auto EquipmentBtn = tgui::Button::create("Equipment");
    EquipmentBtn->setSize(100, 40);
    EquipmentBtn->setPosition(210, 6);
    EquipmentBtn->onClick([this, EquipmentBtn]()
        {
            std::cout << "EquipmentBtn button clicked!\n";
            isopenEquipmentShop = !isopenEquipmentShop;

            if (isopenEquipmentShop)
            {
                isopenClickDmgShop = false;
                isopenBackGroundShop = false;
                isopenPetShop = false;
                isopenArtifactShop = false;

                ClickDmgShop->close();
                BackGroundShop->close();
                ArtifactShop->close();
                PetShop->close();
                EquipmentShop->open();

            }
            else
            {
                EquipmentShop->close();
            }
        });



    panel->add(EquipmentBtn);
}

//Pet button that shows Pet items or hide them
void shop::Pet()
{
    auto PetBtn = tgui::Button::create("Pet");
    PetBtn->setSize(100, 40);
    PetBtn->setPosition(310, 6);
    PetBtn->onClick([this, PetBtn]()
        {
            std::cout << "PetBtn button clicked!\n";
            isopenPetShop = !isopenPetShop;

            if (isopenPetShop)
            {
                isopenClickDmgShop = false;
                isopenBackGroundShop = false;
                isopenEquipmentShop = false;
                isopenArtifactShop = false;

                ClickDmgShop->close();
                BackGroundShop->close();
                EquipmentShop->close();
                ArtifactShop->close();
                PetShop->open();
            }
            else
            {
                PetShop->close();
            }
        });

    panel->add(PetBtn);
}

//Artifact button that shows Artifact items or hide them
void shop::Artifact()
{
    auto ArtifactBtn = tgui::Button::create("Artifact");
    ArtifactBtn->setSize(100, 40);
    ArtifactBtn->setPosition(410, 6);
    ArtifactBtn->onClick([this, ArtifactBtn]()
        {
            std::cout << "ArtifactBtn button clicked!\n";
            isopenArtifactShop = !isopenArtifactShop;

            if (isopenArtifactShop)
            {
                isopenClickDmgShop = false;
                isopenBackGroundShop = false;
                isopenEquipmentShop = false;
                isopenPetShop = false;

                ClickDmgShop->close();
                BackGroundShop->close();
                EquipmentShop->close();
                PetShop->close();
                ArtifactShop->open();

            }
            else
            {
                ArtifactShop->close();

            }
        });
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
