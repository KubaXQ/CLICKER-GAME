#include "ClickDmgShop.h"

ClickDmgShop::ClickDmgShop(tgui::Gui& gui) : gui(gui)
{
	
}

void ClickDmgShop::item1()
{
	win1 = tgui::ChildWindow::create("Item 1");
	win1->setSize(100, 100);
	win1->setPosition(100, 100);
	gui.add(win1);
}
