//
// CryptXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:18:46 2016 Florian Saurs
// Last update Mon Apr 18 09:20:54 2016 Nyrandone Noboud-Inpeng
//

#include "CryptXor.hpp"

CryptXor::CryptXor() {}

CryptXor::~CryptXor() {}

std::string	CryptXor::Decrypt(std::string msg, unsigned char, uint16_t key) const
{
  int		pos;
  char		keyFirst;

  if (key > 255)
    {
      keyFirst = key >> 8;
      for (pos = 0; msg[pos] > 0; pos++)
  	{
  	  if (pos % 2)
  	    msg[pos] = msg[pos] ^ key;
  	  else
  	    msg[pos] = msg[pos] ^ keyFirst;
  	}
    }
  else
    for (pos = 0; msg[pos]; pos++)
      msg[pos] = msg[pos] ^ key;
  return (msg);
}
