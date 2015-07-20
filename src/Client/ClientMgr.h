#ifndef CLIENTMGR_H
#define CLIENTMGR_H

#include <list>
#include "Client.h"

class ClientMgr
{
	public:
		static void SendPacketToAll(sf::Packet packet);
		static void RecievePackets(sf::SocketSelector* selector);
		static void CreateClient(sf::TcpListener* listener, sf::SocketSelector* selector);
		static void DeleteClient();

	private:
		static std::list<Client*>* clients;
		// static sf::SocketSelector* selector;
};

#endif