//
// TimerError.cpp for TimerError in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sat Apr 16 20:02:26 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:36:33 2016 Florian Saurs
//

#include "TimerError.hh"

TimerError::TimerError(std::string const &message)
{
  _message = message;
}

TimerError::~TimerError() throw() {}
