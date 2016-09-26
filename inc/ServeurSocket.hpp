//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Mon Apr 18 20:45:58 2016 Florian Saurs
//

#ifndef SERVEURSOCKET_HPP_
# define SERVEURSOCKET_HPP_

# include "ASocket.hpp"

class	ServeurSocket : public ASocket
{
public:
  ServeurSocket();
  ~ServeurSocket();

  int		destroy() const;
  int		read(t_processState &) const;
  int		write(t_processState &) const;

  ServeurSocket	*getServeurSocket() const;
};

#endif /* !SERVEURSOCKET_HPP_ */
