#include "Client.h"

using namespace std;
using namespace sf;

void Client::setId(int id)
{
	_id = id
}

int Client::getId()
{
	return id;
}

void Client::setUsername(string username)
{
	_username = username
}

string Client::getUsername()
{
	return username;
}