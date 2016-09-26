//
// GUI.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Apr 17 19:57:03 2016 guillaume wilmot
// Last update Sun Apr 24 23:24:49 2016 guillaume wilmot
//

#ifndef GUI_HPP_
# define GUI_HPP_

# include <iostream>
# include <dirent.h>
# include <ncurses/curses.h>
# include "Core.hpp"
# include "MenuFiles.hpp"
# include "MenuTasks.hpp"

class		Gui
{
public:
  Gui();
  ~Gui();

  void			startMenu(Communication);
  void			init(Core *);
  static void		handleResize();

private:
  void			changeDir(std::string &, DIR **) const;

  Menu			*_menuFiles;
  Menu			*_menuTasks;
  std::string		_order;
  Core			*_core;
};

#endif /* !GUI_HPP_ */
