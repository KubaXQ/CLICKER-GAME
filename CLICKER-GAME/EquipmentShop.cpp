#include "EquipmentShop.h"

EquipmentShop::EquipmentShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money) : BaseShop(parentPanel, multiplier, money)
{
	setupItems();
}

void EquipmentShop::setupItems()
{
	createItem("Ziemia", 25, 0, 155, 3, 20, "src/stone_sword.png", "Ziemia jest piekna planeta i daje ci +");
	createItem("Niebo", 25, 203, 355, 203, 220, "src/stone_sword.png", "Ziemia jest piekna planeta i daje ci +");
	createItem("Pustynia", 25, 406, 555, 403, 420, "src/stone_sword.png", "Ziemia jest piekna planeta i daje ci +");

}
