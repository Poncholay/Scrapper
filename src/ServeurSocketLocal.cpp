//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Sun Apr 24 23:14:17 2016 guillaume wilmot
//

#include "ServeurSocketLocal.hpp"
#include "CommunicationError.hh"

ServeurSocketLocal::ServeurSocketLocal(const std::string &path)
{
  struct sockaddr_un socketAddress;

  _path = path;
  _clientSocket = -1;
  unlink(_path.c_str());
  _socket = socket(AF_UNIX, SOCK_STREAM, 0);
  _clientReceiveSize = sizeof(_clientUnixSocket);
  if (_socket != INVALID_SOCKET)
    {
      socketAddress.sun_family = AF_UNIX;
      strcpy(socketAddress.sun_path, _path.c_str());
      _unixSocket = socketAddress;
      _socketError = bind(_socket, (sockaddr*)&_unixSocket, sizeof(_unixSocket));
      if (_socketError == SOCKET_ERROR)
	throw CommunicationError("Error: bind error.");
      else
	_socketError = listen(_socket, 5);
    }
  else
    throw CommunicationError("Error: socket error.");
}

ServeurSocketLocal::~ServeurSocketLocal()
{
  unlink(_path.c_str());
}

int		ServeurSocketLocal::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ServeurSocketLocal::read(t_processState &state) const
{
  if (_clientSocket == -1)
    if ((const_cast<ServeurSocketLocal *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientUnixSocket, &const_cast<ServeurSocketLocal *>(this)->_clientReceiveSize)) == -1)
      throw CommunicationError("Error: accept error.");
  if (::read(_clientSocket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}

int		ServeurSocketLocal::write(t_processState &state) const
{
  if (_clientSocket == -1)
    if ((const_cast<ServeurSocketLocal *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientUnixSocket, &const_cast<ServeurSocketLocal *>(this)->_clientReceiveSize)) == -1)
       throw CommunicationError("Error: accept error.");
  if (::write(_clientSocket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
