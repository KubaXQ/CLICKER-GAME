#include "ClickDmgShop.h"
#include <iostream>

ClickDmgShop::ClickDmgShop(tgui::Panel::Ptr parentPanel) : parentPanel(parentPanel)
{
    if (!parentPanel)
    {
        std::cout << "parentPanel == nullptr! Nie mo¿na utworzyæ ClickDmgShop.\n";
        return;
    }

    Mainpan = tgui::ScrollablePanel::create({ "100%", "100%" });
    Mainpan->setVisible(false);
    Mainpan->getRenderer()->setBackgroundColor(tgui::Color::White);
    Mainpan->setPosition(100, 100);
    Mainpan->setSize(500, 500);

    parentPanel->add(Mainpan);
}

void ClickDmgShop::open()
{
    if (Mainpan)
        Mainpan->setVisible(true);
}

void ClickDmgShop::close()
{
    if (Mainpan)
        Mainpan->setVisible(false);
}

void ClickDmgShop::items()
{
    if (!Mainpan)
        return;

    item1();
    item2();
}

void ClickDmgShop::item1()
{
    itemLabels[0]->setSize({ "100%", 200 });
    itemLabels[0]->getRenderer()->setBackgroundColor(tgui::Color::White);
    itemLabels[0]->setPosition({ 0, 0 });
    itemLabels[0]->getRenderer()->setBorders({ 3, 3, 3, 3 });
    itemLabels[0]->getRenderer()->setBorderColor(tgui::Color::Black);
    Mainpan->add(itemLabels[0]);
}

void ClickDmgShop::item2()
{
    itemLabels[1]->setSize({ "100%", 200 });
    itemLabels[1]->getRenderer()->setBackgroundColor(tgui::Color::White);
    itemLabels[1]->setPosition({ 0, 200 });
    itemLabels[1]->getRenderer()->setBorders({ 3, 3, 3, 3 });
    itemLabels[1]->getRenderer()->setBorderColor(tgui::Color::Black);
    Mainpan->add(itemLabels[1]);
}
