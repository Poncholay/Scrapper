//
// CommunicationError.hh for CommunicationError in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:29:37 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 08:59:09 2016 Nyrandone Noboud-Inpeng
//

#ifndef COMMUNICATIONERROR_HH_
# define COMMUNICATIONERROR_HH_

# include "Error.hpp"

class			CommunicationError : public Error
{
public:
  CommunicationError(std::string const &message = "An error occured.");
  virtual		~CommunicationError() throw();
};

#endif /* !COMMUNICATIONERROR_HH_ */
