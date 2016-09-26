//
// Sockets.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:10:31 2016 Florian Saurs
// Last update Mon Apr 18 20:54:57 2016 Florian Saurs
//

#include "Sockets.hpp"
#include "ClientSocket.hpp"
#include "ServeurSocket.hpp"

Sockets::Sockets(int)
{
  _serv = new ServeurSocket();
  _client = new ClientSocket();
  _a = 0;
  _first = true;
}

Sockets::Sockets(ServeurSocket *serv)
{
  _first = false;
  _serv = serv;
  _client = new ClientSocket();
  _a = 0;
}

Sockets::~Sockets()
{
  destroy();
}

int	Sockets::write(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<Sockets *>(this)->_a;
      return (_client->write(state));
    }
  else
  {
      --const_cast<Sockets *>(this)->_a;
      return (_serv->write(state));
  }
}

int	Sockets::read(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<Sockets *>(this)->_a;
      return (_serv->read(state));
    }
  else
    {
      --const_cast<Sockets *>(this)->_a;
      return (_client->read(state));
    }
}

int	Sockets::destroy() const
{
  if (_first == true)
    delete _serv;
  delete _client;
  return (0);
}

ServeurSocket	*Sockets::getServeurSocket() const
{
  return (static_cast<ServeurSocket *>(_serv));
}
