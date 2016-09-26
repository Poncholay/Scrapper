//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Mon Apr 18 12:30:48 2016 Florian Saurs
//

#ifndef CLIENTSOCKET_HPP_
# define CLIENTSOCKET_HPP_

# include "ASocket.hpp"

class	ClientSocket : public ASocket
{
public:
  ClientSocket();
  ~ClientSocket();

  int		destroy() const;
  int		read(t_processState &) const;
  int		write(t_processState &) const;
};

#endif /* !CLIENTSOCKET_HPP_ */
