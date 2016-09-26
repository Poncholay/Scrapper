//
// CondThread.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 18:19:02 2016 guillaume wilmot
// Last update Sun Apr 24 22:59:15 2016 guillaume wilmot
//

#include "ScopedLock.hpp"
#include "CondThread.hpp"

CondThread::CondThread() : _cond(_mutex)
{
  _order.set(NULL);
  _looping.set(false);
}

bool		CondThread::isWorking()
{
  if (_mutex.trylock() == 0)
    {
      _mutex.unlock();
      return (_looping.get() ? _order.get() ? true : false : false);
    }
  return (true);
}

void		CondThread::assignOrder(t_queue *order, bool lock)
{
  if (lock)
    _mutex.lock();
  _looping.set(true);
  _order.set(order);
  _cond.signal();
  if (lock)
    _mutex.unlock();
}

void		*CondThread::listen()
{
  ScopedLock	lock(_mutex);
  void		*ret;
  t_queue	*del;

  while (1)
    {
      if (!_order.get())
	_cond.wait();
      if (_order.get())
  	{
  	  ret = _order.get()->ptr(_order.get()->args);
  	  if (ret)
	    {
	      delete _order.get()->args;
	      delete _order.get();
	      return (NULL);
	    }
	  del = _order.get();
	  _order.set(NULL);
	  if (del->args->callback->callback(this) == -1)
	    _looping.set(false);
	  delete del->args;
	  delete del;
  	}
    }
}

void		*CondThread::begin(void *args)
{
  CondThread	*condThread;

  condThread = reinterpret_cast<CondThread *>(args);
  return (condThread->listen());
}
