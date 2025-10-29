#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
class BaseShop
{
protected:
	tgui::Panel::Ptr parentPanel;
	tgui::ScrollablePanel::Ptr Mainpan;
	std::vector<tgui::Label::Ptr> itemLabels;
	std::vector<tgui::Button::Ptr> itemButtons;
	std::vector<tgui::Picture::Ptr> Pictures;
	std::vector<tgui::Label::Ptr> itemdescriptionLabels;
	void createItem(
        const std::string& name,
        float bonus,
        float ylabpos,
		float ybutpos,
		float ypicpos,
		float yitemdescpos,
		const std::string& picname,
		const std::string& itemdesc

    );

public:
	BaseShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money);
	float& multiplier;
	float& money;
	virtual void setupItems() = 0;
	virtual void open();
	virtual void close();
	virtual ~BaseShop() = default;

};

