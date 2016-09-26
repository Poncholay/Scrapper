//
// Communication.hpp for Communication in /home/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sun Apr 17 17:32:19 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 17 21:33:09 2016 guillaume wilmot
//

#ifndef COM_HPP_
# define COM_HPP_

# include "ICommunication.hpp"
# include "CommunicationError.hh"

class				Com : public ICommunication
{
public:
  virtual			~Com() {};
  virtual int			destroy() const = 0;
  virtual int			read(t_processState &) const = 0;
  virtual int			write(t_processState &) const = 0;
  Com				&operator<<(t_processState &ps)
    {
      if (write(ps) == -1)
	throw CommunicationError("");
      return (*this);
    }
  Com				&operator>>(t_processState &ps)
    {
      if (read(ps) == -1)
	throw CommunicationError("");
      return (*this);
    }
};

#endif /* !COM_HPP_ */
