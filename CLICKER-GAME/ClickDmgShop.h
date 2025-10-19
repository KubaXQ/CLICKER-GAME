#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>

class ClickDmgShop
{
public:
    explicit ClickDmgShop(tgui::Panel::Ptr parentPanel);
    void open();
    void close();
    void items();
    void item1();
    void item2();

    tgui::Panel::Ptr parentPanel;
    tgui::ScrollablePanel::Ptr Mainpan;

    std::vector<tgui::Label::Ptr> itemLabels =
    {
        tgui::Label::create("item1"),
        tgui::Label::create("item2")
    };

    tgui::Borders border;
};
