//
// CondVar.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 14:58:51 2016 guillaume wilmot
// Last update Sun Apr 24 23:00:21 2016 guillaume wilmot
//

#include "CondVar.hpp"

CondVar::CondVar(Mutex &mutex)
{
  _mutex = &mutex;
  pthread_cond_init(&_condition, NULL);
}

CondVar::~CondVar()
{
  pthread_cond_destroy(&_condition);
}

void		CondVar::wait()
{
  pthread_cond_wait(&_condition, _mutex->getMutex());
}

void		CondVar::signal()
{
  pthread_cond_signal(&_condition);
}

void		CondVar::broadcast()
{
  pthread_cond_broadcast(&_condition);
}
