#include <iostream>
#include "ClientMgr.h"

using namespace std;
using namespace sf; // SFML

list<Client*>* ClientMgr::clients = new list<Client*>;
// SocketSelector* ClientMgr::selector = new SocketSelector;

void ClientMgr::SendPacketToAll(Packet packet)
{
	cout << "Send message to clients..." << endl;
	
	for (list<Client*>::iterator it = clients->begin(); it != clients->end(); ++it)
	{
	    Client& client = **it;
	    client.send(packet);
	}
}

void ClientMgr::RecievePackets(SocketSelector* selector)
{
	for (list<Client*>::iterator it = clients->begin(); it != clients->end(); ++it)
	{
		Client& client = **it;
		if (selector->isReady(client))
		{
		  	string message;
		  	Packet packet;

		  	cout << "New message from : " << client.getRemoteAddress() << endl;

		  	if (client.receive(packet) == Socket::Done)
		    {
			    if (packet >> message)
				{
					cout << message << endl;
					SendPacketToAll(packet);
				}
			    else
				{
					cout << "Message could not be read !" << endl;
				}
		    }
		    else
		    {
		    	cout << "Can not receive packet..." << endl;
		    }
		}
	}
}

void ClientMgr::CreateClient(TcpListener* listener, SocketSelector* selector)
{
	Client* client = new Client;
	if (listener->accept(*client) == Socket::Done)
	{
		clients->push_back(client);
		selector->add(*client);

		cout << "New client connected !" << endl;
		cout << "Client Remote Address : " << client->getRemoteAddress() << endl;
		cout << "Client Remote Port : " << client->getRemotePort() << endl;
	}
	else
	{
		delete client;
	}
}

void ClientMgr::DeleteClient()
{

}
