//
// Listener.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:31 2016 guillaume wilmot
// Last update Sun Apr 24 23:06:38 2016 guillaume wilmot
//

#ifndef LISTENER_HPP_
# define LISTENER_HPP_

# include "ThreadPool.hpp"
# include "Com.hpp"
# include "Process.hpp"
# include "Timer.hh"

class		Listener
{
public:
  Listener();
  ~Listener() {}

  void		init(int, Com *);
  void		*listen();
  bool		timeOut() const;

  static void	*start(void *);
  static void	end(int);
  static void	handler(int);
  static void	setCom(Com *);
  static Com	*getCom(Com *);

  t_processState	*getTask(ThreadPool &);

private:
  Com			*_com;
  unsigned int		_nbThread;
  Timer			_timer;
};

#endif /* !LISTENER_HPP_ */
