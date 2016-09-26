//
// ThreadPool.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:30:45 2016 guillaume wilmot
// Last update Thu Apr 21 21:43:52 2016 guillaume wilmot
//

#include <signal.h>
#include "ScopedLock.hpp"
#include "ThreadPool.hpp"
#include "Listener.hpp"

bool		g_end = false;

ThreadPool::ThreadPool(int nbThread)
{
  _nbThread = nbThread;
  _working = 0;
  _timer = NULL;
}

void		ThreadPool::setTimer(Timer *timer)
{
  _timer = timer;
}

int		ThreadPool::init(void *(*ptr)(void *))
{
  int		i;

  for (i = 0; i < _nbThread; i++)
    {
      CondThread	*thread;

      thread = new CondThread;
      thread->start(ptr, thread);
      _threads.push_back(thread);
    }
  return (0);
}

int		ThreadPool::callback(CondThread *ref)
{
  ScopedLock	lock(_mutex);

  _working--;
  return (assign(ref, false));
}

int		ThreadPool::queue(void *(*ptr)(void *), Information order, const std::string &file)
{
  ScopedLock	lock(_mutex);
  t_queue	*elem = new t_queue;

  _timer->setTime(0);
  elem->args = new t_args;
  elem->args->callback = this;
  elem->args->order = order;
  elem->args->file = file;
  elem->ptr = ptr;
  _stack.push_back(elem);
  tryAssign();
  return (0);
}

int		ThreadPool::assign(CondThread *ref, bool lock)
{

  if (_stack.size() == 0)
    {
      if (g_end)
	Listener::handler(0);
      _timer->setTime(5);
      return (-1);
    }
  ref->assignOrder(_stack.front(), lock);
  _working++;
  _stack.erase(_stack.begin());
  return (0);
}

int		ThreadPool::tryAssign()
{
  if (_working >= _nbThread || _stack.size() == 0)
    return (-1);
  for (unsigned int i = 0; i < _threads.size(); i++)
    if (!_threads[i]->isWorking())
      return (assign(_threads[i], true));
  return (0);
}

unsigned int	ThreadPool::getQueueSize()
{
  ScopedLock	lock(_mutex);

  return (_stack.size());
}

unsigned int	ThreadPool::getWorking()
{
  ScopedLock	lock(_mutex);

  return (_working);
}

unsigned int	ThreadPool::getTotalOrders()
{
  ScopedLock	lock(_mutex);

  return (_working + _stack.size());
}
