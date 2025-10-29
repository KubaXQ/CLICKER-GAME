#pragma once
#include "BaseShop.h"

class EquipmentShop : public BaseShop
{
public:
    EquipmentShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money);
    void setupItems() override;
};

