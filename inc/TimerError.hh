//
// TimerError.hh for TimerError in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sat Apr 16 20:01:33 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 20:27:09 2016 Nyrandone Noboud-Inpeng
//

#ifndef TIMERERROR_HH_
# define TIMERERROR_HH_

# include "Error.hpp"

class			TimerError : public Error
{
public:
  TimerError(std::string const &message = "An error occured.");
  virtual		~TimerError() throw();
};

#endif /* !TIMERERROR_HH_ */
