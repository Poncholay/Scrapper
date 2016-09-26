//
// ThreadPool.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:29:53 2016 guillaume wilmot
// Last update Thu Apr 21 21:39:15 2016 guillaume wilmot
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

# include <iostream>
# include <vector>
# include "Mutex.hpp"
# include "CondThread.hpp"
# include "Queue.hpp"
# include "Timer.hh"

extern bool			g_end;

class				CondThread;

class				ThreadPool {
public:
  ThreadPool(int);
  ~ThreadPool() {}

  int			callback(CondThread *);
  int			assign(CondThread *, bool);
  int			tryAssign();
  int			init(void *(*)(void *));
  int			queue(void *(*)(void *), Information, const std::string &);
  unsigned int		getQueueSize();
  unsigned int		getWorking();
  unsigned int		getTotalOrders();
  void			setTimer(Timer *);

private:
  int				_nbThread;
  int				_working;
  Mutex				_mutex;
  Timer				*_timer;
  std::vector<CondThread *>	_threads;
  std::vector<t_queue *>	_stack;
};

#endif /* !THREADPOOL_HPP_ */
