//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Sun Apr 24 23:06:34 2016 guillaume wilmot
//

#include <unistd.h>
#include <cstring>
#include <signal.h>
#include "Listener.hpp"
#include "ReadAndFind.hh"
#include "CommunicationError.hh"

Listener::Listener()
{
  _com = NULL;
  _nbThread = 0;
  _timer.setTime(5);
  signal(SIGUSR2, &Listener::end);
  signal(SIGUSR1, &Listener::handler);
  signal(SIGINT, SIG_IGN);
}

void			Listener::end(int)
{
  g_end = true;
}

void			Listener::handler(int)
{
  Com			*com = NULL;

  signal(SIGUSR1, SIG_IGN);
  com = getCom(NULL);
  try {
    delete com;
    setCom(NULL);
  } catch (const CommunicationError &e) {
    std::cerr << e.what() << std::endl;
  }
  _exit(EXIT_SUCCESS);
}

void			Listener::setCom(Com *com)
{
  getCom(com);
}

Com			*Listener::getCom(Com *com)
{
  static Com		*_com = NULL;

  _com = com ? com : _com;
  return (_com);
}

void			Listener::init(int nbThread, Com *com)
{
  _nbThread = nbThread;
  _com = com;
  setCom(_com);
}

t_processState		*Listener::getTask(ThreadPool &threadPool)
{
  t_processState	*struc;

  struc = new t_processState;
  memset(struc, 0, sizeof(*struc));
  try {
    *_com >> *struc;
  } catch (const CommunicationError &e) {
    delete struc;
    throw CommunicationError();
  }
  if (struc->state == FREE)
    struc->free = threadPool.getTotalOrders() < _nbThread * 2 ? true : false;
  if (struc->state == STATE)
    {
      struc->threads[0] = _nbThread;
      struc->threads[1] = threadPool.getWorking();
      struc->threads[2] = threadPool.getQueueSize();
    }
  try {
    *_com << *struc;
  } catch  (const CommunicationError &e) {
    return (NULL);
  }
  if (struc->state == ASSIGN)
    return (struc);
  delete struc;
  return (NULL);
}

bool			Listener::timeOut() const
{
  return (_timer.isElapsed() ? true : false);
}

void			*Listener::listen()
{
  ThreadPool		threadPool(_nbThread);
  t_processState	*struc;

  threadPool.init(&CondThread::begin);
  threadPool.setTimer(&_timer);
  while (1)
    {
      try {
	if ((struc = getTask(threadPool)))
	  {
	    threadPool.queue(&ReadAndFind::execute, struc->info, struc->fileName);
	    delete struc;
	  }
      } catch (const CommunicationError &e) {
	if (threadPool.getTotalOrders() == 0)
	  _exit(0);
	pause();
	_exit(0);
      }
    }
  return (NULL);
}

void			*Listener::start(void *args)
{
  Listener		_this;
  t_processArgs		*tab;

  tab = reinterpret_cast<t_processArgs *>(args);
  _this.init(tab->nbThread, tab->com);
  try {
    return (_this.listen());
  } catch (const CommunicationError &e) {
    std::cerr << e.what() << std::endl;
  }
  return (NULL);
}
