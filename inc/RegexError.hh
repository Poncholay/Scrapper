//
// RegexError.hh for RegexError in /home/noboud_n/rendu/cpp_plazza/inc
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.net>
//
// Started on  Mon Apr 18 08:58:28 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 08:59:29 2016 Nyrandone Noboud-Inpeng
//

#ifndef REGEXERROR_HH_
# define REGEXERROR_HH_

# include "Error.hpp"

class			RegexError : public Error
{
public:
  RegexError(std::string const &message = "An error occured.");
  virtual		~RegexError() throw();
};

#endif /* !REGEXERROR_HH_ */
