#include <iostream>
#include "Server/Server.h"

using namespace std;

int main()
{
  cout << "Welcome to ComNetService !" << endl;

  Server server(9983);

  switch (server.getStatus())
  {
    case Server::Listening:
        cout << "Server is starting..." << endl;
        server.start();
    break;

    case Server::NotReady:
        cout << "Server is not ready" << endl;
    break;

    case Server::Disconnected:
        cout << "The server has disconnected. Trying to reconnect..." << endl;
    break;

    case Server::ListeningError:
        cout << "The server can not listen on port : " << server.getLocalPort() << endl;
        return (1);
    break;

    default:
        cout << "Unknown error" << endl;
    break;
  }

  return (0);
}
