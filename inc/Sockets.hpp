//
// Sockets.hpp for plazza in /home/saurs_f/cpp_plazza/inc/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:11:38 2016 Florian Saurs
// Last update Mon Apr 18 20:55:16 2016 Florian Saurs
//

#ifndef SOCKETS_HPP_
# define SOCKETS_HPP_

# include "ASocket.hpp"
# include "ServeurSocket.hpp"

class	Sockets : public ASocket
{
public:
  Sockets(int);
  Sockets(ServeurSocket *);
  ~Sockets();

  int			write(t_processState &) const;
  int			read(t_processState &) const;
  int			destroy() const;
  ServeurSocket		*getServeurSocket() const;

private:
  ASocket		*_serv;
  ASocket		*_client;
  int			_id;
  int			_a;
  bool			_first;
};

#endif /* !SOCKETS_HPP_ */
