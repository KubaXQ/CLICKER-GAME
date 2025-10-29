#pragma once
#include "BaseShop.h"

class PetShop : public BaseShop
{
public:
    PetShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money);
    void setupItems() override;
};

