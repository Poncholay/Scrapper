//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr 21 16:40:26 2016 guillaume wilmot
//

#include "ParseAv.hpp"
#include "Error.hpp"

int					main(int, char **av)
{
  ParseAv	*pars = new ParseAv(av);

  try {
    if (pars->pars() == -1)
      return (0);
  } catch (const Error &e) {
    std::cerr << e.what() << std::endl;
    return (-1);
  }

  Core		*core = new Core(pars->getNbThread());

  try {
    core->read(pars->getComWay());
  } catch (const Error &e) {
    std::cerr << e.what() << std::endl;
  }
  delete core;
  return (0);
}
