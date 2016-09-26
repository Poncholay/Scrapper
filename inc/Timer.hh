//
// Timer.hh for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:43:51 2016 guillaume wilmot
// Last update Sun Apr 24 23:06:01 2016 guillaume wilmot
//

#ifndef TIMER_HH_
# define TIMER_HH_

class	Timer
{
public:
  Timer();
  ~Timer() {}

  void			setTime(int) const;
  bool			isElapsed() const;
private:
  timer_t		_id;
};

#endif /* !TIMER_HH_ */
