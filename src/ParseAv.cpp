//
// ParseAv.cpp for  in /home/saurs_f/cpp_plazza
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Mon Apr 18 21:16:51 2016 Florian Saurs
// Last update Thu Apr 21 20:13:57 2016 Florian Saurs
//

#include <cstring>
#include "ParseAv.hpp"
#include "UsageError.hh"

ParseAv::ParseAv(char **av)
{
  _nbThreads = 2;
  _comWay = NAMED_PIPE;
  _av = av;
  _optionTab.insert(std::pair<std::string, Communication>("--namedpipe", NAMED_PIPE));
  _optionTab.insert(std::pair<std::string, Communication>("--localsocket", LOCAL_SOCKET));
  _optionTab.insert(std::pair<std::string, Communication>("--internetsocket", INTERNET_SOCKET));
  _arg = 0;
}

ParseAv::~ParseAv()
{}

void	ParseAv::takeNbThread(int i)
{
  try {
    _nbThreads = std::stoi(_av[i]);
    ++_arg;
  } catch (const std::invalid_argument &e) {
    throw UsageError("Error: invalid argument, positive number expected as nbThread.");
  }
  if (_nbThreads <= 0)
    {
      throw UsageError("Error: invalid argument, positive number expected as nbThread.");
    }
}

void	ParseAv::takeComWay()
{
  int							i;
  std::map<std::string, Communication>::iterator	it;
  int							found;

  found = 0;
  i = 1;
  while (_av[i])
    {
      if (isNumber(_av[i]) == true)
	takeNbThread(i);
      else
	{
	  for (it = _optionTab.begin(); it != _optionTab.end() && it->first != _av[i]; ++it);
	  if (it != _optionTab.end())
	    {
	      _comWay = it->second;
	      found = 1;
	    }
	  else
	    {
	      usage(1);
	      throw UsageError("Error: expected good argument as way of communication.");
	    }
	}
      ++i;
    }
  if (found != 1 && _av[1] && i == 1 && _arg == 0)
    {
      usage(1);
      throw UsageError("Error: expected good argument as way of communication.");
    }
}

int	ParseAv::pars()
{
  int	i;
  int	fullNb;

  if (usage(0) == true)
    return (-1);
  i = 1;
  fullNb = 0;
  while (_av[i])
    {
      if (isNumber(_av[i]) == true)
	++fullNb;
      ++i;
    }
  if (fullNb > 1 || i > 3)
    {
      usage(1);
      return (0);
    }
  i = 1;
  takeComWay();
  return (0);
}

bool	ParseAv::usage(int i) const
{
  bool	printUsage;

  printUsage = false;
  if (i == 1)
    printUsage = true;
  else
    {
      while (_av[i] && strcmp(_av[i], "--help") != 0)
	++i;
      if (_av[i])
	printUsage = true;
    }
  if (printUsage == true)
    throw UsageError("Usage: ./plazza [nbr of threads] [--namedpipe | --internetsocket | --localsocket]\nPositive non-NULL number expected.");
  return (printUsage);
}

bool	ParseAv::isNumber(const std::string &str) const
{
  if (str[0] == '-')
    return (std::all_of(str.begin() + 1, str.end(), ::isdigit));
  return (std::all_of(str.begin(), str.end(), ::isdigit));
}

int	ParseAv::getNbThread() const
{
  return (_nbThreads);
}

Communication	ParseAv::getComWay() const
{
  return (_comWay);
}
