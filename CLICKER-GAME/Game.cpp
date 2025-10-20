#include "Game.h"

//constructor for whole game
Game::Game() : window(sf::VideoMode({ 1200,600 }), "okno gry", sf::Style::Close | sf::Style::Titlebar), gui(window), shop(gui,multiplier)
{
	
	LoadingFont();
	ShopButton();
	shop.AllButtons();
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
		ClickingEvent(ev,multiplier);
		ShopClickEvent(ev);
	}

}

//event with closing
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

//event that takes adds money when we click on screen
void Game::ClickingEvent(const sf::Event& ev, float multiplier)
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
	}
	else
	{
		shop.hide();
		window.clear();
		DisplayingMoney(money);
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
