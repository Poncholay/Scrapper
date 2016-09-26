//
// UsageError.hh for UsageError in /home/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr 18 06:18:07 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 06:18:54 2016 Nyrandone Noboud-Inpeng
//

#ifndef USAGEERROR_HH_
# define USAGEERROR_HH_

# include "Error.hpp"

class			UsageError : public Error
{
public:
  UsageError(std::string const &message = "An error occured.");
  virtual		~UsageError() throw();
};

#endif /* !USAGEERROR_HH_ */
