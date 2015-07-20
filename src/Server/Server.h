#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <SFML/Network.hpp>

class Server
{
	public:
	enum Status { Listening, NotReady, Disconnected, ListeningError };

	Server(int listening_port);
	~Server();
    void start();
    Status getStatus();
    int getLocalPort();

  private:
    sf::TcpListener listener;
    sf::SocketSelector selector;
    Status status;
    int listening_port;

    void setStatus(Status new_status);
};

#endif
