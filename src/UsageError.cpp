//
// UsageError.cpp for UsageError in /home/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr 18 06:19:05 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:36:40 2016 Florian Saurs
//

#include "UsageError.hh"

UsageError::UsageError(std::string const &message)
{
  _message = message;
}

UsageError::~UsageError() throw() {}
