//
// SocketsLocal.hpp for plazza in /home/saurs_f/cpp_plazza/inc/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:47:20 2016 Florian Saurs
// Last update Mon Apr 18 17:26:58 2016 Florian Saurs
//

#ifndef SOCKETSLOCAL_HPP_
# define SOCKETSLOCAL_HPP_

# include "ASocket.hpp"

class	SocketsLocal : public ASocket
{
public:
  SocketsLocal(int);
  ~SocketsLocal();

  int			write(t_processState &) const;
  int			read(t_processState &) const;
  int			destroy() const;

private:
  ASocket		*_serv;
  ASocket		*_client;
  int			_id;
  int			_a;
};

#endif /* !SOCKETSLOCAL_HPP_ */
