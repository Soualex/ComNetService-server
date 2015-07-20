#ifndef CLIENT_H
#define CLIENT_H

#include <SFML/Network.hpp>

class Client : public sf::TcpSocket
{
	public:
		void setId();
		int getId();
		void setUsername();
		std::string getUsername();

	private:
		int _id;
		std::string _username;
};

#endif