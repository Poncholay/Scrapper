//
// Search.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Sun Apr 24 23:22:38 2016 guillaume wilmot
//

#include "Search.hpp"
#include "Regex.hpp"

Search::Search()
{
  _regs.push_back(new Regex("0[1-9]([ ]?[0-9]{2}){4}"));
  _regs.push_back(new Regex("[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]{2,}\\.[a-zA-Z]{2,63}"));
  _regs.push_back(new Regex("(([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])"));
}

Search::~Search()
{}

std::string	Search::searchInCurrent(const std::string &current, Information type) const
{
  if (type < _regs.size())
    return (_regs[type]->match(current));
  return ("");
}

std::vector<std::string>	Search::parseFile(std::string content, Information type) const
{
  std::string			result("");
  std::string			current;
  std::vector<std::string>	found;

  while (content != "")
    {
      result = searchInCurrent(content, type);
      if (result != "")
	{
	  found.push_back(result);
	  if (content.find(result) == std::string::npos + result.length())
	    content = "";
	  else
	    content = content.substr(content.find(result) + result.length());
	}
      else
	content = "";
    }
  return (found);
}
