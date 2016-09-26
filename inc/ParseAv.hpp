//
// ParseAv.hpp for  in /home/saurs_f/cpp_plazza
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Mon Apr 18 21:16:04 2016 Florian Saurs
// Last update Tue Apr 19 17:50:20 2016 Florian Saurs
//

#ifndef PARSEAV_HPP_
# define PARSEAV_HPP_

#include <algorithm>
#include "Core.hpp"

class	ParseAv
{
public:
  ParseAv(char **);
  ~ParseAv();

  bool	isNumber(const std::string &) const;
  int	pars();
  bool	usage(int) const;
  void	takeNbThread(int);
  void	takeComWay();

  int	getNbThread() const;
  Communication	getComWay() const;

private:
  int					_nbThreads;
  std::map<std::string, Communication>	_optionTab;
  Communication				_comWay;
  char					**_av;
  int					_arg;
};

#endif /* !PARSEAV_HPP_ */
