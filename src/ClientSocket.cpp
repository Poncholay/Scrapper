//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr 19 17:19:11 2016 Florian Saurs
//

#include <iostream>
#include "ClientSocket.hpp"
#include "CommunicationError.hh"

ClientSocket::ClientSocket()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _internetSocket.sin_addr.s_addr = inet_addr("127.0.0.1");
  _internetSocket.sin_family = AF_INET;
  _internetSocket.sin_port = 17030;
  if(connect(_socket, (sockaddr*)&_internetSocket, sizeof(_internetSocket)) == SOCKET_ERROR)
    throw CommunicationError("Error: connection impossible.");
}

ClientSocket::~ClientSocket() {}

int		ClientSocket::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ClientSocket::read(t_processState &state) const
{
  if (recv(_socket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ClientSocket::write(t_processState &state) const
{
  if (send(_socket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
