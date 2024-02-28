#include <iostream>
#include <conio.h>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Chat.h"


void RunClient();
void RunServer();
void RunWindows();

short port = 3000;

int main()
{
	std::cout << "Select" << std::endl << "Client -> C" << std::endl << "Server -> S" ;

	char mode = ' ';

	RunWindows();

	do
	{
		mode = ConsoleControl::WaitForReadNextChar();

	} while (mode != 'C' && mode != 'c' && mode != 'S' && mode != 's');

	switch (mode)
	{
	case 'c':
	case 'C':
	{
		RunClient();
	}
	break;
	case's':
	case 'S':
	{
		RunServer();
	}
	break;
	default:
		break;
	}
	while (true)
	{

	}
}

void RunClient()
{
	std::cout << "Client";

	std::cout << std::endl << "Set server IP -->";

	std::string ip;
	std:getline(std::cin, ip);

	Chat* chat = Chat::Client(ip, port);
}

void RunServer()
{
	std::cout << std::endl << "Server";

	Chat* chat = Chat::Server(port);
}

void RunWindows()
{
	sf::RenderWindow windows;

	windows.create(sf::VideoMode(800, 600), "Chat");
	windows.setFramerateLimit(60);

	sf::Text label;
	sf::Font font;

	font.loadFromFile("Minecraft.ttf");

	label.setFont(font);
	label.setCharacterSize(16);
	label.setFillColor(sf::Color::White);
	label.setString("Hello world");
	label.setOrigin(0.5, 0.5);//Alligement
	label.setPosition(windows.getSize().x / 2, windows.getSize().y / 2);

	while (windows.isOpen())
	{
		windows.clear(sf::Color::Black);
		windows.draw(label);
		windows.display();
	}
}
