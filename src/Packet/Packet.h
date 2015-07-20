#ifndef PACKET_H
#define PACKET_H

#include <iostream>
#include <SFML/Network.hpp>

class Packet : public sf::Packet
{
  public:
    Packet();
    ~Packet();
    void writeMessage();

  private:
    sf::TcpSocket client;

    bool isStandard();
};

#endif