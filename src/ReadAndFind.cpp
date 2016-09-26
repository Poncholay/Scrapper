//
// ReadAndFind.cpp for ReadAndFind in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr 13 14:27:40 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 24 23:21:37 2016 guillaume wilmot
//

#include <fstream>
#include "CryptCaesar.hh"
#include "CryptXor.hpp"
#include "Search.hpp"
#include "ReadAndFind.hh"
#include "Information.hh"
#include "Displayer.hh"

ReadAndFind::ReadAndFind() {}

ReadAndFind::~ReadAndFind() {}

void				*ReadAndFind::execute(void *arg)
{
  t_args			*args;
  args = reinterpret_cast<t_args *>(arg);

  Search			search;
  CryptXor			Xor;
  CryptCaesar			Caesar;
  std::vector<std::string>	found;
  uint16_t			i = 0;
  int				start = 0;
  Displayer			displayer;
  std::string			saveDirectory("logFiles/");
  std::ifstream			file(args->file.c_str(), std::ifstream::in);
  std::string			content((std::istreambuf_iterator<char>(file)),
  					(std::istreambuf_iterator<char>()));
  std::string			saveFile(((args->order == PHONE_NUMBER) ?
					  "_phone_number.log" :
					  args->order == EMAIL_ADDRESS ?
					  "_email_address.log" :
					  args->order == IP_ADDRESS ?
					  "_ip_address.log" : ".log"));

  saveFile = saveDirectory + args->file.substr(args->file.find_last_of("/") + 1) + saveFile;
  std::ofstream			fileOut(saveFile.c_str());

  found = search.parseFile(content, args->order);
  for (start = 0; start <= 255 && found.size() == 0; start++)
    found = search.parseFile(Caesar.Decrypt(content, start, 0), args->order);
  start = 0;
  while ((i != 0 || start == 0) && found.size() == 0)
    {
      start = 1;
      found = search.parseFile(Xor.Decrypt(content, 0, i++), args->order);
    }
  for (std::vector<std::string>::iterator it = found.begin(); it != found.end(); ++it)
    displayer.Display(*it + "\n");
  if (fileOut.is_open())
    {
      for (std::vector<std::string>::iterator it = found.begin(); it != found.end(); ++it)
	fileOut << *it << std::endl;
      fileOut.close();
    }
  file.close();
  return (NULL);
}
