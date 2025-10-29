#include "Game.h"

//constructor for whole game
Game::Game() : window(sf::VideoMode({ 1200,600 }), "okno gry", sf::Style::Close | sf::Style::Titlebar), gui(window), shop(gui,multiplier,money, itemBought)
{
	LoadGame();
	LoadingFont();
	
	shop.AllButtons();
	ClickDmgPic = tgui::Picture::create("src/wooden_sword.jpg");
	ClickDmgPic->setVisible(false);
	GamePanel = tgui::Panel::create({ "100%", "100%" });
	GamePanel->getRenderer()->setBackgroundColor(tgui::Color{ 100, 100, 100, 150 });
	gui.add(GamePanel);
	GamePanel->add(ClickDmgPic);
	ShopButton();
}

//main loop that handle events, displaying everything 
void Game::Running()
{
	while (window.isOpen()) 
	{
		Events();
		Displaying();
		window.clear();
	}
}

//loop that take events and send them to other methods
void Game::Events()
{
	while (auto evOpt = window.pollEvent())
	{
		const sf::Event& ev = *evOpt;
		gui.handleEvent(ev);
		ClosingEvent(ev);
		ClickingEvent(ev);
		ShopClickEvent(ev);
	}

}

//event with closing
void Game::ClosingEvent(const sf::Event& ev)
{
	
		if (ev.is <sf::Event::Closed>())
		{
			SaveGame();
			window.close();
		}
		else if (auto keypressed = ev.getIf<sf::Event::KeyPressed>())
		{
			if (keypressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				SaveGame();
				window.close();
			}
		}
	
}

//event that takes adds money when we click on screen
void Game::ClickingEvent(const sf::Event& ev)
{
	if (auto mouspressed = ev.getIf<sf::Event::MouseButtonPressed>())
	{
		if (mouspressed->button == sf::Mouse::Button::Left)
		{
			money= money + 1 * multiplier;
		}
	}
}

//event that open our shop
void Game::ShopClickEvent(const sf::Event& ev)
{
	if (auto mouspressed = ev.getIf<sf::Event::MouseButtonPressed>())
	{
		if (mouspressed->button == sf::Mouse::Button::Left)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (shopbutton.getGlobalBounds().contains(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))))
			{
				isShopOpen = true;
			}
		}
	}
}

//event that loadsfont
void Game::LoadingFont()
{
	if (!font.openFromFile("Font.ttf")) {
		std::cout << "ERROR FONT NOT LOADED\n";
	}
	
}

//displaying everything
void Game::Displaying()
{
	if (isShopOpen == true)
	{
		shop.show();
		GamePanel->setVisible(false);
	}
	else
	{
		shop.hide();
		window.clear();
		GamePanel->setVisible(true);
		DisplayingMoney(money);
		DisplayingClickDmgItem();
	}
	gui.draw();
	window.display();
}

//displaying money
void Game::DisplayingMoney(float money)
{
	sf::Text moneytext(font);
	moneytext.setCharacterSize(30);
	moneytext.setFillColor(sf::Color::White);
	moneytext.setPosition(sf::Vector2f(1.f, 0.f));
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << money; // np. 123.45
	moneytext.setString("Money: " + ss.str());

	window.draw(moneytext);
}

void Game::DisplayingClickDmgItem()
{
	if (itemBought.empty()) {
		ClickDmgPic->setVisible(false);
		return;
	}

	ClickDmgPic->setVisible(true);
	ClickDmgPic->setPosition({ 1149, 50 });
	ClickDmgPic->setSize({ 50, 50 });

	switch (itemBought.size())
	{
	case 1:
		ClickDmgPic->getRenderer()->setTexture("src/wooden_sword.jpg");

		break;
	case 2:
		ClickDmgPic->getRenderer()->setTexture("src/stone_sword.png");
		break;
	case 3:
		ClickDmgPic->getRenderer()->setTexture("src/iron_sword.jpg");
		break;
	default:
		break;
	};
	

}

//parameters for shop button and handle click event on button
void Game::ShopButton()
{
	auto shopBtn = tgui::Button::create("Shop");
	shopBtn->setSize(100, 40);
	shopBtn->setPosition(1090, 6);

	shopBtn->onClick([this]() {
		isShopOpen = !isShopOpen; // prze³¹czanie stanu sklepu
		std::cout << "Shop button clicked! Shop state = " << isShopOpen << std::endl;
		});
	gui.add(shopBtn);

}

void Game::SaveGame()
{
	std::ofstream save("save.txt");

	if (!save.is_open())
		return;

	save << money << "\n";
	save << multiplier << "\n";
	save << itemBought.size() << "\n";

	for (auto& [id, owned] : itemBought)
	{
		save << id << " " << owned << "\n";
	}

	std::cout << "Game saved!\n";
}

void Game::LoadGame()
{
	std::ifstream load("save.txt");

	if (!load.is_open())
		return;

	itemBought.clear();

	size_t count = 0;
	load >> money;
	load >> multiplier;
	load >> count;

	for (size_t i = 0; i < count; i++)
	{
		int id;
		bool owned;
		load >> id >> owned;
		itemBought[id] = owned;
	}

	std::cout << "Game loaded!\n";
}
