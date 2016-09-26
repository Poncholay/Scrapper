//
// DisplayerGui.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr 20 00:01:08 2016 guillaume wilmot
// Last update Sun Apr 24 23:03:39 2016 guillaume wilmot
//

#include <ncurses.h>
#include "Displayer.hh"

void		Displayer::Display(const std::string &str) const
{
  WINDOW	*_win = newwin(1, str.size() + 13, 4, 40);

  wattron(_win, COLOR_PAIR(2) | A_BOLD);
  wprintw(_win, "%s", "Found -> ");
  wattroff(_win, COLOR_PAIR(2) | A_BOLD);
  wattron(_win, COLOR_PAIR(3) | A_BOLD);
  wprintw(_win, "%s <- ", str.c_str());
  wattroff(_win, COLOR_PAIR(3) | A_BOLD);
  wrefresh(_win);
  werase(_win);
}
