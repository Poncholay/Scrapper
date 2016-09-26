//
// CryptCaesar.cpp for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:34:02 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 09:20:52 2016 Nyrandone Noboud-Inpeng
//

#include "CryptCaesar.hh"

CryptCaesar::CryptCaesar() {}

CryptCaesar::~CryptCaesar() {}

std::string		CryptCaesar::Decrypt(std::string to_decrypt, unsigned char key, uint16_t) const
{
  for (unsigned int i = 0; i < to_decrypt.length(); i++)
    to_decrypt[i] = (to_decrypt[i] - key) % 255;
  return (to_decrypt);
}
