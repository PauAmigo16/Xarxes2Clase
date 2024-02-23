#pragma once
#include "TcpListener.h"

class SocketSelector : sf::SocketSelector
{
private:
	std::mutex _mutex;


public:
	bool Wait();
	bool IsReady(TcpListener& listener);
	bool IsReady(TcpSocket& socket);

	void Add(TcpListener& listener);
	void Add(TcpSocket& socket);

	void Remove(TcpListener& listener);
	void Remove(TcpSocket& socket);
};

