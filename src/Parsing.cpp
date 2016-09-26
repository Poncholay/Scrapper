//
// Parsing.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Sun Apr 24 23:19:17 2016 guillaume wilmot
//

#include <dirent.h>
#include <unistd.h>
#include "Parsing.hpp"
#include "Regex.hpp"

Parsing::Parsing()
{
  _compare.insert(std::pair<std::string, Information>("PHONE_NUMBER", PHONE_NUMBER));
  _compare.insert(std::pair<std::string, Information>("EMAIL_ADDRESS", EMAIL_ADDRESS));
  _compare.insert(std::pair<std::string, Information>("IP_ADDRESS", IP_ADDRESS));
}

Parsing::~Parsing()
{}

int				Parsing::commandIsFalse(const std::string &str) const
{
  Regex		*regex = new Regex ("[0-9a-zA-Z._-]+[ ]{1,}(PHONE_NUMBER|EMAIL_ADDRESS|IP_ADDRESS)");

  return (regex->match(str) == "" ? 1 : 0);
}

void		Parsing::takeCommandFromInput(std::string input, std::vector<std::string> *command) const
{
  int		i;

  while (input.find(";") != std::string::npos)
    {
      i = 1;
      command->push_back(input.substr(0, input.find(";")));
      while (input.c_str()[i + input.find(";")] == ' ' ||
	     input.c_str()[i + input.find(";")] == '\t')
	++i;
      input = input.substr(input.find(";") + i);
    }
  command->push_back(input.substr(0, input.find(";")));
  for (std::vector<std::string>::iterator it = command->begin();
       it != command->end(); ++it)
    {
      if (*it == "" || (i = commandIsFalse(*it)) == 1)
	{
	  if (i == 1)
	    std::cerr << "Wrong argument in line command." << std::endl;
	  it = command->erase(it);
	  --it;
	}
    }
}

int				Parsing::read(Core const *core, Communication _com) const
{
  std::string			input("");
  std::vector<std::string>	*command;

  while (getline(std::cin, input))
    {
      command = new std::vector<std::string>(0, "");
      takeCommandFromInput(input, command);
      const_cast<Parsing *>(this)->parseCommandLine(command, core, _com);
      delete command;
    }
  core->wait();
  return (0);
}

int				Parsing::parseCommandLine(std::vector<std::string> *command, Core const *core, Communication _com)
{
  DIR				*directory;
  std::vector<std::string>	*filesName;

  for (std::vector<std::string>::iterator it = command->begin();
       it != command->end(); ++it)
    {
      filesName = new std::vector<std::string>(0, "");
      while ((*it).find(" ") != std::string::npos)
	{
	  filesName->push_back((*it).substr(0, (*it).find(" ")));
	  *it = (*it).substr((*it).find(" ") + 1);
	}
      for (std::vector<std::string>::iterator itFiles = filesName->begin();
	   itFiles != filesName->end(); ++itFiles)
	{
	  t_args	*a = new t_args;

	  a->callback = NULL;
	  a->order = _compare.at(*it);
	  a->file = *itFiles;
	  if (access((*itFiles).c_str(), F_OK) == -1)
	    std::cerr << *itFiles << ": file doesn't exist." << std::endl;
	  else if (access((*itFiles).c_str(), R_OK) == -1)
	    std::cerr << *itFiles << ": file cannot be read." << std::endl;
	  else if ((directory = opendir((*itFiles).c_str())) != NULL)
	    {
	      std::cerr << *itFiles << ": is a directory." << std::endl;
	      closedir(directory);
	    }
	  else
	    const_cast<Core *>(core)->runProcess(*itFiles, _compare.at(*it), _com);
	}
      delete filesName;
    }
  return (0);
}
