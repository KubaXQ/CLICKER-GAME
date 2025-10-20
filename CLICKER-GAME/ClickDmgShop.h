#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>

class ClickDmgShop
{
public:
    explicit ClickDmgShop(tgui::Panel::Ptr parentPanel, float& multiplier);
    void open();
    void close();
    void items();
    void item1();
    void item2();
    void item3();

    float multiplier;

    tgui::Panel::Ptr parentPanel;
    tgui::ScrollablePanel::Ptr Mainpan;

    //array for all itemLabels
    std::vector<tgui::Label::Ptr> itemLabels =
    {
        tgui::Label::create("Drewniany miecz    KOSZT: 200"),
        tgui::Label::create("Kamienny miecz     KOSZT: 500"),
        tgui::Label::create("Zelazny miecz      KOSZT: 1000")

    };

    //array for all Pictures
    std::vector<tgui::Picture::Ptr> Pictures =
    {
        tgui::Picture::create("src/wooden_sword.jpg"),
        tgui::Picture::create("src/stone_sword.png"),
        tgui::Picture::create("src/iron_sword.jpg")




    };

    //array for all itemdescription
    std::vector<tgui::Label::Ptr> itemdescriptionLabels =
    {
        tgui::Label::create("Zwieksza klikanie o 1.2"),
        tgui::Label::create("Zwieksza klikanie o 1.5"),
        tgui::Label::create("Zwieksza klikanie o 2")

    };

    //array for all Buttons
    std::vector<tgui::Button::Ptr> Buttons =
    {
        tgui::Button::create("button1"),
        tgui::Button::create("button2"),
        tgui::Button::create("button3")

    };

};
