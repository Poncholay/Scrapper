//
// Menu.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 03:57:07 2016 guillaume wilmot
// Last update Sun Apr 24 23:26:32 2016 guillaume wilmot
//

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <iostream>
#include "MenuTasks.hpp"
#include "Gui.hpp"

MenuTasks::MenuTasks(Core *core) : Menu(core)
{
  _items = NULL;
  _nbItem = 0;

  _choices.push_back("PHONE_NUMBER");
  _choices.push_back("EMAIL_ADDRESS");
  _choices.push_back("IP_ADDRESS");
}

MenuTasks::~MenuTasks() {}

int				MenuTasks::init(const std::vector<std::string> &)
{
  unsigned int                  i;

  _items = new ITEM *[_choices.size() + 1];
  for (i = 0; i < _choices.size(); ++i)
    _items[i] = new_item(_choices[i].c_str(), _choices[i].c_str());
  _items[i] = NULL;
  _nbItem = _choices.size();
  if (!(_menu = new_menu(_items)))
    return (-1);
  return (0);
}

int				MenuTasks::initWindow()
{
  if (!(_win = newwin(LINES - 10, COLS - 10, 5, 5)) ||
      !(_subWin = derwin(_win, LINES - 11, COLS - 13, 1, 1)))
    return (-1);
  keypad(_win, TRUE);
  set_menu_win(_menu, _win);
  set_menu_sub(_menu, _subWin);
  set_menu_format(_menu, LINES - 17, 1);
  set_menu_mark(_menu, " ");
  set_menu_fore(_menu, COLOR_PAIR(4));
  menu_opts_off(_menu, O_SHOWDESC);
  post_menu(_menu);
  return (0);
}

void				MenuTasks::draw() const
{
  int				x;
  int				y;
  int				x2;
  int				y2;

  box(_win, 0, 0);
  getmaxyx(_subWin, y, x);
  mvwaddch(_subWin, y - 1, 3, ACS_LRCORNER);
  mvwaddch(_subWin, y - 2, 3, ACS_ULCORNER);
  for (int i = 0; i < 39; i ++)
    {
      getyx(_subWin, y2, x2);
      if (y2 == y - 2 && x2 < x - 1)
	waddch(_subWin, ACS_HLINE);
    }
  if (y2 == y - 2 && x2 < x - 2)
    waddch(_subWin, ACS_URCORNER);
  else
    waddch(_subWin, ACS_LRCORNER);
  mvwprintw(_subWin, y - 1, 4, "ESCAPE ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Quit");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " ENTER ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Start");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " ARROWS ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Navigate");
  wattroff(_subWin, COLOR_PAIR(1));
  getyx(_subWin, y2, x2);
  if (y2 == y - 1 && x2 < x - 2)
    waddch(_subWin, ACS_LLCORNER);
  wrefresh(_win);
}

void				MenuTasks::free()
{
  unpost_menu(_menu);
  free_menu(_menu);
  for (unsigned int i = 0; i < _nbItem; i++)
    free_item(_items[i]);
  delete[] _items;
}

void				MenuTasks::setTasks()
{
  _ret += item_name(current_item(_menu));
}

int				MenuTasks::events()
{
  int				c;

  while ((c = wgetch(_win)) != 27)
    {
      switch (c)
	{
	case KEY_DOWN:
	  menu_driver(_menu, REQ_DOWN_ITEM);
	  break;
	case KEY_UP:
	  menu_driver(_menu, REQ_UP_ITEM);
	  break;
	case KEY_LEFT:
	  menu_driver(_menu, REQ_LEFT_ITEM);
	  break;
	case KEY_RIGHT:
	  menu_driver(_menu, REQ_RIGHT_ITEM);
	  break;
	case 10:
	  setTasks();
	  return (0);
	  break;
	case KEY_RESIZE:
	  Gui::handleResize();
	  return (2);
	  break;
	default:
	  break;
	}
      draw();
    }
  return (-1);
}

std::string			MenuTasks::getRet()
{
  std::string			ret;

  ret = _ret;
  _ret.clear();
  return (ret);
}
