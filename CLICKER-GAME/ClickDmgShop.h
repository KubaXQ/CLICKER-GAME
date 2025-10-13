#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>
class ClickDmgShop
{
public:
	explicit ClickDmgShop(tgui::Gui& gui);
	void open();
	void close();
	void items();
	void item1();
	void item2();
	tgui::Gui& gui;
	tgui::ScrollablePanel::Ptr Mainpan;
	std::vector<tgui::Panel::Ptr> itemPanels = 
	{
	tgui::Panel::create({ "90%", "90%" }),
	tgui::Panel::create({ "90%", "90%" })
	};
	std::vector<tgui::Label::Ptr> itemLabels =
	{
	tgui::Label::create("item1"),
	tgui::Label::create("item2")
	};
	tgui::Label::Ptr lab1;
	tgui::Borders border;
};

