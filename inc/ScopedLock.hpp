//
// ScopedLock.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:11 2016 guillaume wilmot
// Last update Tue Apr 19 17:52:37 2016 Florian Saurs
//

#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

# include "Mutex.hpp"

class ScopedLock
{
public:
  ScopedLock(Mutex &mutex) {_lock = &mutex; _lock->lock();}
  ~ScopedLock() {_lock->unlock();}
private:
  Mutex		*_lock;
};

#endif /* !SCOPEDLOCK_HPP_ */
