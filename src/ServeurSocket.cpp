//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr 19 17:34:01 2016 Florian Saurs
//

#include "ServeurSocket.hpp"
#include "CommunicationError.hh"

ServeurSocket::ServeurSocket()
{
  _clientSocket = -1;
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _clientReceiveSize = sizeof(_clientInternetSocket);
  if (_socket != INVALID_SOCKET)
    {
      _internetSocket.sin_addr.s_addr = inet_addr("127.0.0.1");
      _internetSocket.sin_family = AF_INET;
      _internetSocket.sin_port = 17030;
      _socketError = bind(_socket, (sockaddr*)&_internetSocket, sizeof(_internetSocket));
      if (_socketError != SOCKET_ERROR)
	{
	  _socketError = listen(_socket, 1000000);
	  if (_socketError == SOCKET_ERROR)
	    throw CommunicationError("Error: listen error.");
	}
    }
  else
    throw CommunicationError("Error: socket error.");
}

ServeurSocket::~ServeurSocket() {}

int		ServeurSocket::destroy() const
{
  closesocket(_clientSocket);
  closesocket(_socket);
  return (0);
}

int		ServeurSocket::read(t_processState &state) const
{
  if (_clientSocket == -1)
    const_cast<ServeurSocket *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientInternetSocket, const_cast<socklen_t *>(&_clientReceiveSize));
  if (recv(_clientSocket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ServeurSocket::write(t_processState &state) const
{
  if (send(_clientSocket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
