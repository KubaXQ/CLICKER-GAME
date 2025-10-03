#include "Shop.h"

shop::shop(tgui::Gui& gui) : gui(gui)
{
	
}

void shop::AllButtons()
{
	ClickDmg();
	BackGroundButton();
	Equipment();
	Pet();
	Artifact();
}

void shop::ClickDmg()
{
	auto ClickDmgBtn = tgui::Button::create("ClickDmg");
	ClickDmgBtn->setPosition(10, 6);
	ClickDmgBtn->setSize(100, 40);
	ClickDmgBtn->onClick([ClickDmgBtn]()
		{
			ClickDmgBtn->setTextSize(200);
			
		});
	
	gui.add(ClickDmgBtn);
	//dodac mozliwosc kilikanai i zmiany wtedy wielkosci czcionki
}

void shop::BackGroundButton()
{
	auto shopBtn = tgui::Button::create("BackGround");
	shopBtn->setSize(100, 40);
	shopBtn->setPosition(110, 6);

	shopBtn->onClick([]() 
		{
		//narazie nic
		});
	gui.add(shopBtn);
}

void shop::Equipment()
{
	auto EquipmentBtn = tgui::Button::create("Equipment");
	EquipmentBtn->setSize(100, 40);
	EquipmentBtn->setPosition(210, 6);

	EquipmentBtn->onClick([]()
		{
			//narazie nic
		});
	gui.add(EquipmentBtn);
}

void shop::Pet()
{
	auto PetBtn = tgui::Button::create("Pet");
	PetBtn->setSize(100, 40);
	PetBtn->setPosition(310, 6);

	PetBtn->onClick([]()
		{
			//narazie nic
		});
	gui.add(PetBtn);
}

void shop::Artifact()
{
	auto ArtifactBtn = tgui::Button::create("Artifact");
	ArtifactBtn->setSize(100, 40);
	ArtifactBtn->setPosition(410, 6);

	ArtifactBtn->onClick([]()
		{
			//narazie nic
		});
	gui.add(ArtifactBtn);
}

