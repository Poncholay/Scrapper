//
// Error.hpp for Error in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr  8 10:56:46 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:47:09 2016 Florian Saurs
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <stdexcept>

class			Error : public std::exception
{
public:
  Error() {};
  ~Error() {};

  virtual char const	*what() const throw();
protected:
  std::string		_message;
};

#endif /* ERROR_HPP_ */
