#include "Game.h"

Game::Game() : window(sf::VideoMode({ 1200,600 }), "okno gry", sf::Style::Close | sf::Style::Titlebar), gui(window), shop(gui)
{
	
	LoadingFont();
	ShopButton();
}

void Game::Running()
{
	while (window.isOpen()) 
	{
		Events();
		Displaying();
		window.clear();
	}
}

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

void Game::ClosingEvent(const sf::Event& ev)
{
	
		if (ev.is <sf::Event::Closed>())
		{
			window.close();
		}
		else if (auto keypressed = ev.getIf<sf::Event::KeyPressed>())
		{
			if (keypressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				window.close();
			}
		}
	
}

void Game::ClickingEvent(const sf::Event& ev)
{
	if (auto mouspressed = ev.getIf<sf::Event::MouseButtonPressed>())
	{
		if (mouspressed->button == sf::Mouse::Button::Left)
		{
			money++;
		}
	}
}

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

void Game::LoadingFont()
{
	if (!font.openFromFile("Font.ttf")) {
		std::cout << "ERROR FONT NOT LOADED\n";
	}
	
}

void Game::Displaying()
{
	if (isShopOpen == true)
	{
		shop.AllButtons();
	}
	else
	{
		window.clear();
		DisplayingMoney(money);
	}
	gui.draw();
	window.display();
}

void Game::DisplayingMoney(int cash)
{
	sf::Text moneytext(font);
	moneytext.setCharacterSize(30);
	moneytext.setFillColor(sf::Color::White);
	moneytext.setPosition(sf::Vector2f(1.f, 0.f));
	moneytext.setString("Money: " + std::to_string(cash));
	window.draw(moneytext);
	
}
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
