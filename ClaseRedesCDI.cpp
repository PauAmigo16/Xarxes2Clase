#include <iostream>
#include <conio.h>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Chat.h"

#include "ConnectionAbstraction/SocketManager.h"
#include "WindowsHelpers/Window.h"

void RunClient();
void RunServer();
void RunWindows();

short port = 3000;

enum PackagesIds: Packet::PacketKey{Message=0};

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
	std::cout << std::endl << "Set server IP --> ";

	std::string ip;
	std::getline(std::cin, ip);

	//Chat* chat = Chat::Client(ip, port);
	SocketManager* SM = new SocketManager([](TcpSocket* socket)
		{
			std::cout << std::endl << "Socket connected" << socket->getRemoteAddress().toString();

			socket->Subscribe(Message, [socket](Packet packet)
				{
					std::string message;
					packet >> message;
					std::cout << std::endl << "New Message: " << message;
				});

			socket->SubscribeOnDisconnect([](TcpSocket* socket)
				{
					std::cout << std::endl << "Socket disconnected: " << socket->getRemoteAddress().toString();
				});

			std::string message = "I am the client";
			Packet packet;
			packet << message;

			socket->Send(Message, packet);
		});

	if (SM->ConnectToServer(ip, port))
	{
		SM->StartLoop();
	}
}

void RunServer()
{
	std::cout << "Server";

	//Chat* chat = Chat::Server(port);

	SocketManager* SM = new SocketManager([](TcpSocket* socket)
		{
			std::cout << std::endl << "Socket connected: " << socket->getRemoteAddress().toString();

			socket->Subscribe(Message, [socket](Packet packet)
				{
					std::string message;
					packet >> message;
					std::cout << std::endl << "New Message: " << message;

					std::string response = "I am the server";
					Packet responsePacket;
					responsePacket << response;

					socket->Send(Message, responsePacket);
				});

			socket->SubscribeOnDisconnect([](TcpSocket* socket)
				{
					std::cout << std::endl << "Socket disconnected" << socket->getRemoteAddress().toString();
				});
		});
}

void RunWindows()
{
	/*sf::RenderWindow windows;

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
	}*/

	Window window;

	Button* bt = new Button(50, 20, "Piezas/QG.png");
	bt->onClick = []() {
		std::cout << std::endl << "Long Live The Queen";
		};

	window.AddButton(bt);
	window.RunWindowLoop();
}
