//
// Thread.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:40 2016 guillaume wilmot
// Last update Sun Apr 24 23:11:15 2016 guillaume wilmot
//

#ifndef THREAD_HPP_
# define THREAD_HPP_

class		Thread
{
public:
  Thread();
  ~Thread() {}

  void		start(void *(*)(void *), void *);
  void		join() const;
  bool		getStatus() const;
private:
  pthread_t	_thread;
  bool		_started;
};

#endif /* !THREAD_HPP_ */
