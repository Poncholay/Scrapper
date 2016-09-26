//
// Parsing.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:35 2016 Florian Saurs
// Last update Sun Apr 24 23:21:04 2016 guillaume wilmot
//

#ifndef PARSING_HPP_
# define PARSING_HPP_

# include "Core.hpp"

class	Parsing
{
  std::map<std::string, Information>	_compare;

  public:
  Parsing();
  ~Parsing();

  int	commandIsFalse(const std::string &) const;
  int	read(Core const *, Communication) const;
  void	takeCommandFromInput(std::string, std::vector<std::string> *) const;
  int	parseCommandLine(std::vector<std::string> *, Core const *, Communication);
};

#endif /* !PARSING_HPP_ */
