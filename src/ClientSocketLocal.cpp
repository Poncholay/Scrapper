//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr 19 17:19:16 2016 Florian Saurs
//

#include <iostream>
#include "ClientSocketLocal.hpp"
#include "CommunicationError.hh"

ClientSocketLocal::ClientSocketLocal(std::string path)
{
  struct sockaddr_un socketAddress;

  _path = path;
  _socket = socket(AF_UNIX, SOCK_STREAM, 0);
  socketAddress.sun_family = AF_UNIX;
  strcpy(socketAddress.sun_path, _path.c_str());
  _unixSocket = socketAddress;
  if(connect(_socket, (sockaddr*)&_unixSocket, sizeof(_unixSocket)) == SOCKET_ERROR)
    throw CommunicationError("Error: local connection impossible.");
}

ClientSocketLocal::~ClientSocketLocal() {}

int		ClientSocketLocal::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ClientSocketLocal::read(t_processState &state) const
{
  if (::read(_socket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}

int		ClientSocketLocal::write(t_processState &state) const
{
  if (::write(_socket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
