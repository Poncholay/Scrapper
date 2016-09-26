//
// Mutex.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:22 2016 guillaume wilmot
// Last update Tue Apr 19 18:02:28 2016 Saursinet
//

#ifndef MUTEX_HPP_
# define MUTEX_HPP_

# include <pthread.h>
# include "IMutex.hpp"

class Mutex : public IMutex
{
public:
  Mutex() {pthread_mutex_init(&_mutex, NULL);}
  ~Mutex() {pthread_mutex_destroy(&_mutex);}

  void lock() {pthread_mutex_lock(&_mutex);}
  void unlock() {pthread_mutex_unlock(&_mutex);}
  bool trylock() {return (pthread_mutex_trylock(&_mutex));}
  pthread_mutex_t	*getMutex() {return (&_mutex);}
private:
  pthread_mutex_t	_mutex;
};

#endif /* !MUTEX_HPP_ */
