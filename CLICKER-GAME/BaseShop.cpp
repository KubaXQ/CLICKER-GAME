#include "BaseShop.h"


BaseShop::BaseShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money) : parentPanel(parentPanel), multiplier(multiplier), money(money)
{
    Mainpan = tgui::ScrollablePanel::create({ "100%", "100%" });
    Mainpan->setVisible(false);
    Mainpan->getRenderer()->setBackgroundColor(tgui::Color::White);
    Mainpan->setPosition(100, 100);
    Mainpan->setSize(800, 1000);
    Mainpan->setContentSize({ 1000,2000 });
    parentPanel->add(Mainpan);
}
void BaseShop::createItem(const std::string& name,float bonus,float ylabpos,float ybutpos,float ypicpos,float yitemdescpos,const std::string& picname,const std::string& itemdesc)
{
    auto label = tgui::Label::create(name);
    label->setSize({ "100%", 200 });
    label->setPosition({ 0,ylabpos });
    label->setTextSize(20);
    label->getRenderer()->setBorders({ 3, 3, 3, 3 });
    label->getRenderer()->setBorderColor(tgui::Color::Black);

    auto button = tgui::Button::create("BUY");
    button->setPosition({ 675, ybutpos });
    button->setSize(100, 40);
    button->onClick([this, button, bonus]() {
        button->setText("SOLD");
        multiplier *= bonus;
        std::cout << "Multiplier: " << multiplier << "\n";
        });

    auto itemdescription = tgui::Label::create(itemdesc);
    itemdescription->setSize({ 200,50 });
    itemdescription->setPosition({ 0, yitemdescpos });

    tgui::Texture texture{ picname };
    auto Picture = tgui::Picture::create(texture);
    Picture->setSize({ 50,50 });
    Picture->setPosition({ 730,ypicpos });

    Mainpan->add(label);
    Mainpan->add(button);
    Mainpan->add(itemdescription);
    Mainpan->add(Picture);

    itemLabels.push_back(label);
    itemButtons.push_back(button);
    Pictures.push_back(Picture);
    itemdescriptionLabels.push_back(itemdescription);
}
void BaseShop::open() 
{
    Mainpan->setVisible(true);
}
void BaseShop::close() 
{
    Mainpan->setVisible(false); 

}
