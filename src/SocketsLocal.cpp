//
// SocketsLocal.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:43:02 2016 Florian Saurs
// Last update Thu Apr 21 20:12:12 2016 Florian Saurs
//

#include "SocketsLocal.hpp"
#include "ClientSocketLocal.hpp"
#include "ServeurSocketLocal.hpp"

SocketsLocal::SocketsLocal(int id) : _id(id)
{
  std::string	tmp;

  srand(time(NULL));
  for (int i = 0; i < 20 + rand() % 40; i++)
    tmp += rand() % 2 ? 48 + rand() % 9 : rand() % 2 ? 65 + rand() % 25 : 97 + rand() % 25;
  _path = std::string("./socket") + std::to_string(_id) + tmp;
  _serv = new ServeurSocketLocal(_path);
  _client = new ClientSocketLocal(_path);
  _a = 0;
}

SocketsLocal::~SocketsLocal()
{
  destroy();
}

int	SocketsLocal::write(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<SocketsLocal *>(this)->_a;
      return (_client->write(state));
    }
  else
  {
      --const_cast<SocketsLocal *>(this)->_a;
      return (_serv->write(state));
  }
}

int	SocketsLocal::read(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<SocketsLocal *>(this)->_a;
      return (_serv->read(state));
    }
  else
    {
      --const_cast<SocketsLocal *>(this)->_a;
      return (_client->read(state));
    }
}

int	SocketsLocal::destroy() const
{
  delete _serv;
  delete _client;
  unlink(_path.c_str());
  return (0);
}
