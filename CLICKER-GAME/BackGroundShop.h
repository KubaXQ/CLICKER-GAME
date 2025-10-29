#pragma once
#include "BaseShop.h"

class BackGroundShop : public BaseShop
{
public:
    BackGroundShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money);
    void setupItems() override;
};

