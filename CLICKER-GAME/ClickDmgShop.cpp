#include "ClickDmgShop.h"
#include <iostream>

//constructor clickdmg with parameters
ClickDmgShop::ClickDmgShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money, std::map<int, bool>& itemBought) : parentPanel(parentPanel), multiplier(multiplier), money(money), itemBought(itemBought)
{

    Mainpan = tgui::ScrollablePanel::create({ "100%", "100%" });
    Mainpan->setVisible(false);
    Mainpan->getRenderer()->setBackgroundColor(tgui::Color::White);
    Mainpan->setPosition(100, 100);
    Mainpan->setSize(800, 1000);
    Mainpan->setContentSize( {1000,2000});

    parentPanel->add(Mainpan);
    item1();
    item2();
    item3();
}

//method open seting Mainpan visible
void ClickDmgShop::open()
{
        Mainpan->setVisible(true);
}

//method close seting Mainpan unvisible

void ClickDmgShop::close()
{
        Mainpan->setVisible(false);
}

//parameters for window item 1
void ClickDmgShop::item1()
{
    itemLabels[0]->setSize({ "100%", 200 });
    itemLabels[0]->getRenderer()->setBackgroundColor(tgui::Color::White);
    itemLabels[0]->setPosition({ 0, 0 });
    itemLabels[0]->getRenderer()->setBorders({ 3, 3, 3, 3 });
    itemLabels[0]->getRenderer()->setBorderColor(tgui::Color::Black);

    itemdescriptionLabels[0]->setSize({ 200,50 });
    itemdescriptionLabels[0]->setPosition({ 0, 20 });
    
    Pictures[0]->setSize({ 50,50 });
    Pictures[0]->setPosition({ 730,3 });

    Buttons[0]->setSize(100, 40);
    Buttons[0]->setPosition(675, 155);
    Buttons[0]->setText("BUY");
    

    Buttons[0]->onClick([this]() 
        {
        if (money >= 200 && Buttons[0]->getText() == "BUY")
        {
            this->Buttons[0]->setText("SOLD");
            multiplier *= 1.2f;
            money -= 200;
            itemBought[0] = true;
        }
        else {
            std::cout << "U dont have money" << std::endl;
        }
        });
   
    Mainpan->add(itemLabels[0]);
    Mainpan->add(itemdescriptionLabels[0]);
    Mainpan->add(Pictures[0]);
    Mainpan->add(Buttons[0]);
}

//parameters for window item 2
void ClickDmgShop::item2()
{
    itemLabels[1]->setSize({ "100%", 200 });
    itemLabels[1]->getRenderer()->setBackgroundColor(tgui::Color::White);
    itemLabels[1]->setPosition({ 0, 203 });
    itemLabels[1]->getRenderer()->setBorders({ 3, 3, 3, 3 });
    itemLabels[1]->getRenderer()->setBorderColor(tgui::Color::Black);

    itemdescriptionLabels[1]->setSize({ 200,50 });
    itemdescriptionLabels[1]->setPosition({ 0, 220 });

    Pictures[1]->setSize({ 50,50 });
    Pictures[1]->setPosition({ 730,203 });

    Buttons[1]->setSize(100, 40);
    Buttons[1]->setPosition(675, 355);
    Buttons[1]->setText("BUY");

    Buttons[1]->onClick([this]()
        {
            if (money >= 500 && Buttons[1]->getText() == "BUY")
            {
                this->Buttons[1]->setText("SOLD");
                multiplier *= 1.5f;
                money -= 500;
                itemBought[1] = true;
            }
            else {
                std::cout << "U dont have money" << std::endl;
            }
        });

    Mainpan->add(itemLabels[1]);
    Mainpan->add(itemdescriptionLabels[1]);
    Mainpan->add(Pictures[1]);
    Mainpan->add(Buttons[1]);
}

//parameters for window item 3
void ClickDmgShop::item3()
{
    itemLabels[2]->setSize({ "100%", 200 });
    itemLabels[2]->getRenderer()->setBackgroundColor(tgui::Color::White);
    itemLabels[2]->setPosition({ 0, 406 });
    itemLabels[2]->getRenderer()->setBorders({ 3, 3, 3, 3 });
    itemLabels[2]->getRenderer()->setBorderColor(tgui::Color::Black);

    itemdescriptionLabels[2]->setSize({ 200,50 });
    itemdescriptionLabels[2]->setPosition({ 0, 420 });

    Pictures[2]->setSize({ 50,50 });
    Pictures[2]->setPosition({ 730,413 });

    Buttons[2]->setSize(100, 40);
    Buttons[2]->setPosition(675, 555);
    Buttons[2]->setText("BUY");

    Buttons[2]->onClick([this]()
        {
            if (money >= 1000 && Buttons[2]->getText() == "BUY")
            {
                this->Buttons[2]->setText("SOLD");
                multiplier *= 2.f;
                money -= 1000;
                itemBought[2] = true;
            }
            else {
                std::cout << "U dont have money" << std::endl;
            }
        });

    Mainpan->add(itemLabels[2]);
    Mainpan->add(itemdescriptionLabels[2]);
    Mainpan->add(Pictures[2]);
    Mainpan->add(Buttons[2]);
}
