//
// CryptXor.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:19:09 2016 Florian Saurs
// Last update Mon Apr 18 09:20:32 2016 Nyrandone Noboud-Inpeng
//

#ifndef CRYPTXOR_HPP_
# define CRYPTXOR_HPP_

# include "ICrypt.hpp"

class	CryptXor : public ICrypt
{
public:
  CryptXor();
  ~CryptXor();

  std::string	Decrypt(std::string, unsigned char, uint16_t) const;
};

#endif /* !CRYPTXOR_HPP_ */
