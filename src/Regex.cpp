//
// Regex.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Tue Apr 19 12:00:38 2016 Florian Saurs
// Last update Sun Apr 24 23:22:06 2016 guillaume wilmot
//

#include <regex.h>
#include <cstring>
#include "Regex.hpp"
#include "RegexError.hh"

Regex::Regex(const std::string &pattern)
{
  _pattern = pattern;
}

Regex::~Regex()
{}

std::string	Regex::match(const std::string &str) const
{
  regex_t	regStruc;
  int		match;
  regmatch_t	*found;

  if (regcomp(&regStruc, _pattern.c_str(), REG_EXTENDED) == -1)
    throw RegexError("Invalid regex");
  found = new regmatch_t;

  match = regexec(&regStruc, str.c_str(), 1, found, 0);
  regfree(&regStruc);

  if (match == 0)
    {
      char		*result;
      size_t		size;

      size = found[0].rm_eo - found[0].rm_so;
      if (size == 0)
	return ("");
      result = new char[size + 1];

      strncpy(result, &str.c_str()[found[0].rm_so], size);
      result[size] = 0;
      return (result);
      delete [] result;
    }
  return ("");
}
