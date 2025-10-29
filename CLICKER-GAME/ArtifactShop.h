#pragma once
#include "BaseShop.h"

class ArtifactShop : public BaseShop
{
public:

	ArtifactShop(tgui::Panel::Ptr parentPanel, float& multiplier, float& money);
	void setupItems() override;
};

