//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Mon Apr 18 12:36:22 2016 Florian Saurs
//

#ifndef CLIENTSOCKETLOCAL_HPP_
# define CLIENTSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ClientSocketLocal : public ASocket
{
public:
  ClientSocketLocal(std::string);
  ~ClientSocketLocal();

  int		create(int);
  int		destroy() const;
  int		read(t_processState &) const;
  int		write(t_processState &) const;
};

#endif /* !CLIENTSOCKETLOCAL_HPP_ */
