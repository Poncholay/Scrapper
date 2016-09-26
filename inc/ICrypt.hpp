//
// ICrypt.hpp for ICrypt in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:29:44 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 09:20:43 2016 Nyrandone Noboud-Inpeng
//

#ifndef ICRYPT_HPP_
# define ICRYPT_HPP_

# include <iostream>

class			ICrypt
{
public:
  virtual		~ICrypt() {};
  virtual std::string	Decrypt(std::string, unsigned char, uint16_t) const = 0;
};

#endif /* !ICRYPT_HPP_ */
