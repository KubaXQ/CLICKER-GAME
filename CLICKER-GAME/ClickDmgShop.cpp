#include "ClickDmgShop.h"

ClickDmgShop::ClickDmgShop(tgui::Gui& gui) : gui(gui)
{
	Mainpan = tgui::ScrollablePanel::create({ "100%", "100%" });
	Mainpan->setVisible(false);
	Mainpan->setSize(500, 500);
	Mainpan->getRenderer()->setBackgroundColor(tgui::Color::White);
	Mainpan->setPosition(100, 100);
	gui.add(Mainpan);
}

void ClickDmgShop::open()
{
	Mainpan->setVisible(true);
}

void ClickDmgShop::close()
{
	Mainpan->setVisible(false);
}

void ClickDmgShop::items()
{
	item1();
}

void ClickDmgShop::item1()
{
	itemPanels[0]->getRenderer()->setBorders({ 3, 3, 3, 3 });
	itemPanels[0]->getRenderer()->setBorderColor(tgui::Color::Black);

	itemLabels[0]->setSize(50, 50);
	itemLabels[0]->getRenderer()->setBackgroundColor(tgui::Color::Cyan);


	Mainpan->add(itemPanels[0]);
	Mainpan->add(itemLabels[0]);
	
}

void ClickDmgShop::item2()
{
	//sadas
}
