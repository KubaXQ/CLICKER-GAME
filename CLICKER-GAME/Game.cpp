#include "Game.h"

Game::Game() : window(sf::VideoMode({ 1200,600 }), "okno gry", sf::Style::Close | sf::Style::Titlebar)
{
	LoadingFont();
}

void Game::Running()
{
	while (window.isOpen()) 
	{
		Events();
		DisplayingMoney(money);
		window.display();
		window.clear();
	}
}

void Game::Events()
{
	while (auto evOpt = window.pollEvent())
	{
		const sf::Event& ev = *evOpt;
		ClosingEvent(ev);
		ClickingEvent(ev);
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

void Game::LoadingFont()
{
	if (!font.openFromFile("Font.ttf")) {
		std::cout << "ERROR FONT NOT LOADED\n";
	}
	
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
