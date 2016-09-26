//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Sun Apr 24 23:14:22 2016 guillaume wilmot
//

#ifndef SERVEURSOCKETLOCAL_HPP_
# define SERVEURSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ServeurSocketLocal : public ASocket
{
public:
  ServeurSocketLocal(const std::string &);
  ~ServeurSocketLocal();

  int		create(int);
  int		destroy() const;
  int		read(t_processState &) const;
  int		write(t_processState &) const;
};

#endif /* !SERVEURSOCKETLOCAL_HPP_ */
