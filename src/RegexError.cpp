//
// RegexError.cpp for RegexError in /home/noboud_n/rendu/cpp_plazza/src
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Mon Apr 18 08:57:22 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:32:35 2016 Florian Saurs
//

#include "RegexError.hh"

RegexError::RegexError(std::string const &message)
{
  _message = message;
}

RegexError::~RegexError() throw() {}
