//
// CondThread.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:40 2016 guillaume wilmot
// Last update Sun Apr 24 22:59:17 2016 guillaume wilmot
//

#ifndef CONDTHREAD_HPP_
# define CONDTHREAD_HPP_

# include "Thread.hpp"
# include "CondVar.hpp"
# include "ThreadPool.hpp"
# include "Queue.hpp"
# include "ProtectedVar.hpp"

class		ThreadPool;

class		CondThread : public Thread
{
public:
  CondThread();
  ~CondThread() {}

  bool		isWorking();
  void		wake();
  void		sleep();
  void		assignOrder(t_queue *, bool);
  void		*listen();
  static void	*begin(void *);

private:
  CondVar		_cond;
  Mutex			_mutex;
  ProtectedVar<bool>	_looping;
  ProtectedVar<t_queue *> _order;
};

#endif /* !CONDTHREAD_HPP_ */
