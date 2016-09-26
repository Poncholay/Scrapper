//
// MainGui.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr 19 23:00:57 2016 guillaume wilmot
// Last update Thu Apr 21 18:22:34 2016 guillaume wilmot
//

#include "Core.hpp"
#include "Error.hpp"
#include "Gui.hpp"
#include "ParseAv.hpp"

int		main(int, char **av)
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
  Gui           gui;

  gui.init(core);
  gui.startMenu(pars->getComWay());
  delete core;
  return (0);
}
