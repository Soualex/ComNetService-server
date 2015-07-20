#include <iostream>
#include "../Server/Server.h"
#include "../Client/ClientMgr.h"

using namespace std;

Server::Server(int port) : listening_port(port)
{
 	if (listener.listen(port) == sf::Socket::Done)
	{
		cout << "Server is listening on port : " << port << endl;
		setStatus(Server::Listening);
		selector.add(listener);
	}
	else
	{
		setStatus(Server::ListeningError);
	}	
}

Server::~Server()
{
	listener.close();
}

void Server::start()
{
	cout << "Server started sucessfuly !" << endl;

  	while (status == Server::Listening)
	{
	    if (selector.wait())
	    {
	        if (selector.isReady(listener))
	        {
	          	cout << "New client is ready" << endl;
	            ClientMgr::CreateClient(&listener, &selector);
	        }
	        else
	        {
	        	// Receving packet
	          	cout << "Check messages..." << endl;
	            ClientMgr::RecievePackets(&selector);

	            // Checking packet

	            // Send packet to all
	        }
	    }
	}

	listener.close();
}

Server::Status Server::getStatus()
{
	return status;
}

void Server::setStatus(Server::Status new_status)
{
	status = new_status;
}

int Server::getLocalPort()
{
	return (listening_port);
}