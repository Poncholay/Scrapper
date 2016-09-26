//
// CryptCaesar.hh for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:31:54 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 09:20:29 2016 Nyrandone Noboud-Inpeng
//

#ifndef CRYPTCAESAR_HH_
# define CRYPTCAESAR_HH_

# include "ICrypt.hpp"

class			CryptCaesar : public ICrypt
{
public:
  CryptCaesar();
  ~CryptCaesar();

  std::string		Decrypt(std::string, unsigned char, uint16_t) const;
};

#endif /* !CRYPTCAESAR_HH_ */
