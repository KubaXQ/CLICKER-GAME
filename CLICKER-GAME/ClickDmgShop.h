#pragma once
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
class ClickDmgShop
{
public:
	explicit ClickDmgShop(tgui::Gui& gui);
	void item1();
	tgui::Gui& gui;
	tgui::ChildWindow::Ptr win1;

};

