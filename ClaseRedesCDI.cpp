#include <iostream>
#include <conio.h>
#include <SFML/Network.hpp>

#include "ConsoleControl.h"

void RunClient();
void RunServer();

short port = 3000;

int main()
{
	std::cout << "Select" << std::endl << "Client -> C" << std::endl << "Server -> S" << std::endl;

	char mode = ' ';

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

	/*sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("10.40.2.193", port);

	if (status != sf::Socket::Done) 
	{

		std::cout << "Error on connect to server" << std::endl;
		return;
	}

	while (true) 
	{
		std::cout << "Next Message: ";
		std::string message;
		std::getline(std::cin, message);

		char data[100];

		int stringSize = message.length();
		for (int i = 0; i < stringSize; i++) 
		{
			//ESTEM TREBALLANT AMB CHARs
			char c = message[i];
			data[i] = c;
		}

		if (socket.send(data, 100) != sf::Socket::Done) 
		{
			std::cout << std::endl << "Error sending message";
		}
	}*/
}

void RunServer()
{
	std::cout << "Server" << std::endl;

	/*sf::TcpListener listener;

	if (listener.listen(3000) != sf::Socket::Done) 
	{
		std::cout << "Error on accept Client" << std::endl;
		return;
	}

	sf::IpAddress ipAddress = sf::IpAddress::getLocalAddress();
	std::cout << "Listening on IP: " + ipAddress.toString() << std::endl;

	sf::TcpSocket client;

	if (listener.accept(client) != sf::Socket::Done) 
	{
		std::cout << "Error on accept Client" << std::endl;
		return;
	}

	std::cout << "Client Connected" << client.getRemoteAddress().toString();

	while (true) 
	{
		char data[100];
		std::size_t received;

		std::string message;

		if (client.receive(data, 100, received) != sf::Socket::Done) 
		{
			std::cout << std::endl << "Error receive message";
		}
		else 
		{
			for (size_t i = 0; i < received; i++) 
			{
				char c = data[i];
				message += c;
			}
			std::cout << std::endl << message;
		}
	}*/
}
