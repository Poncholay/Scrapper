//
// Parsing.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:35 2016 Florian Saurs
// Last update Sun Apr 24 23:23:27 2016 guillaume wilmot
//

#ifndef SEARCH_HPP_
# define SEARCH_HPP_

# include <vector>
# include "Core.hpp"
# include "Regex.hpp"

class	Search
{
  std::vector<Regex *>	_regs;

public:
  Search();
  ~Search();

  std::vector<std::string>	parseFile(std::string, Information) const;
  std::string			searchInCurrent(const std::string &, Information) const;
  std::string			compareToReg(std::string) const;
};

#endif /* !SEARCH_HPP_ */
