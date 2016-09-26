//
// IPipe.hpp for IPipe in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:09:05 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 18:22:40 2016 guillaume wilmot
//

#ifndef IPIPE_HPP_
# define IPIPE_HPP_

# include "ICommunication.hpp"

class		IPipe
{
public:
  virtual	~IPipe() {};
  virtual void	destroy() const = 0;
  virtual int	write(t_processState &) = 0;
  virtual int	read(t_processState &) = 0;
  virtual int	getReadFd() const = 0;
  virtual int	getWriteFd() const = 0;
  virtual void	setReadFd(int const &) = 0;
  virtual void	setWriteFd(int const &) = 0;
};

#endif /* !IPIPE_HPP_ */
