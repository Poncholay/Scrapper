//
// Menu.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 03:57:07 2016 guillaume wilmot
// Last update Sun Apr 24 23:26:20 2016 guillaume wilmot
//

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstring>
#include "MenuFiles.hpp"
#include "Gui.hpp"

MenuFiles::MenuFiles(Core *core) : Menu(core)
{
  _items = NULL;
  _nbItem = 0;
}

MenuFiles::~MenuFiles() {}

int				MenuFiles::init(const std::vector<std::string> &choices)
{
  std::vector<std::string>	dirs;
  std::vector<std::string>	files;
  struct stat			path_stat;
  unsigned int                  i;
  int				j = 0;

  _items = new ITEM *[choices.size() + 1];
  for (i = 0; i < choices.size(); ++i)
    {
      stat(choices[i].c_str(), &path_stat);
      if (!S_ISREG(path_stat.st_mode))
	dirs.push_back(choices[i]);
      else
	files.push_back(choices[i]);
    }
  for (i = 0; i < dirs.size(); ++i)
    {
      _items[j++] = new_item(strdup(dirs[i].c_str()), strdup(dirs[i].c_str()));
      item_opts_off(_items[i], O_SELECTABLE);
    }
  for (i = 0; i < files.size(); ++i)
    _items[j++] = new_item(strdup(files[i].c_str()), strdup(files[i].c_str()));
  _items[j] = NULL;
  _nbItem = choices.size();
  if (!(_menu = new_menu(_items)))
    return (-1);
  menu_opts_off(_menu, O_ONEVALUE);
  menu_opts_off(_menu, O_SHOWDESC);
  return (0);
}

int				MenuFiles::initWindow()
{
  unsigned int			size = 0;

  if (!(_win = newwin(LINES - 2, COLS - 2, 1, 1)) ||
      !(_subWin = derwin(_win, LINES - 7, COLS - 3, 5, 1)))
    return (-1);
  wtimeout(_win, 1000);
  keypad(_win, TRUE);
  set_menu_win(_menu, _win);
  set_menu_sub(_menu, _subWin);
  for (int i = 0; i < item_count(_menu); ++i)
    if (std::string(item_name(_items[i])).size() > size)
      size = std::string(item_name(_items[i])).size();
  set_menu_format(_menu, LINES - 9, (COLS - 5) / (size ? size + 2 : 20));
  set_menu_mark(_menu, "-");
  set_menu_fore(_menu, COLOR_PAIR(4));
  set_menu_grey(_menu, COLOR_PAIR(5));
  post_menu(_menu);
  return (0);
}

void				MenuFiles::printThreads() const
{
  int				res[3];

  memset(res, 0, sizeof(res));
  _core->getThreadStatus(res);
  mvwprintw(_win, 3, 1, "Tasks: ");
  wattron(_win, A_BOLD);
  wprintw(_win, "%d", res[2]);
  wattroff(_win, A_BOLD);
  wprintw(_win, ", ");
  wattron(_win, A_BOLD);
  wprintw(_win, "%d", res[0]);
  wattroff(_win, A_BOLD);
  wprintw(_win, " threads, ");
  wattron(_win, A_BOLD);
  wattroff(_win, COLOR_PAIR(2));
  wattron(_win, COLOR_PAIR(3));
  wprintw(_win, "%d", res[1]);
  wattroff(_win, COLOR_PAIR(3));
  wattron(_win, COLOR_PAIR(2));
  wattroff(_win, A_BOLD);
  wprintw(_win, " running");
  wattroff(_win, COLOR_PAIR(2));
}

void				MenuFiles::printDirectory(int x) const
{
  char				cwd[x - 2 < 15 ? 15 : x - 2];

  wattron(_win, COLOR_PAIR(2));
  mvwprintw(_win, 1, 1, "Directory: ");
  wattron(_win, A_BOLD);
  wattroff(_win, A_BOLD);
  if (getcwd(cwd, sizeof(cwd)) == NULL)
    strcpy(cwd, "Too long");
  wprintw(_win, "%s", cwd);
}

void				MenuFiles::printHelp(int y) const
{
  mvwprintw(_subWin, y - 1, 4, "ESCAPE ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Quit");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " ENTER ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Validate");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " SPACE ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Select");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " ARROWS ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Navigate");
  wattroff(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, " E ");
  wattron(_subWin, COLOR_PAIR(1));
  wprintw(_subWin, "Enter Dir");
  wattroff(_subWin, COLOR_PAIR(1));
}

void				MenuFiles::draw() const
{
  int				x;
  int				y;
  int				x2;
  int				y2;

  box(_win, 0, 0);
  getmaxyx(_subWin, y, x);
  printDirectory(x);
  printThreads();
  printHelp(y);
  mvwaddch(_subWin, y - 1, 3, ACS_LRCORNER);
  mvwaddch(_subWin, y - 2, 3, ACS_ULCORNER);
  for (int i = 0; i < 67; i ++)
    {
      getyx(_subWin, y2, x2);
      if (y2 == y - 2 && x2 < x - 1)
	waddch(_subWin, ACS_HLINE);
    }
  getmaxyx(_win, y, x);
  getyx(_subWin, y2, x2);

  if (y2 == y - 7 && x2 < x - 2)
    waddch(_subWin, ACS_URCORNER);
  else
    waddch(_subWin, ACS_LRCORNER);
  getyx(_subWin, y2, x2);
  if (x2 != 0)
    mvwaddch(_subWin, y - 6, x2 - 1, ACS_LLCORNER);
  wrefresh(_win);
}

void				MenuFiles::free()
{
  unpost_menu(_menu);
  free_menu(_menu);
  for (unsigned int i = 0; i < _nbItem; i++)
    free_item(_items[i]);
  delete[] _items;
}

void				MenuFiles::setFiles()
{
  for (int i = 0; i < item_count(_menu); ++i)
    if (item_value(_items[i]) == TRUE)
      _ret += std::string(item_name(_items[i])) + " ";
}

int				MenuFiles::events()
{
  struct stat			path_stat;
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
	case ' ':
	  stat(item_name(current_item(_menu)), &path_stat);
	  if (S_ISREG(path_stat.st_mode))
	    menu_driver(_menu, REQ_TOGGLE_ITEM);
	  break;
	case 10:
	  for (int i = 0; i < item_count(_menu); ++i)
	    if (item_value(_items[i]) == TRUE)
	      {
		setFiles();
		return (0);
	      }
	  break;
	case 'e':
	  stat(item_name(current_item(_menu)), &path_stat);
	  if (!S_ISREG(path_stat.st_mode))
	    {
	      _dir = item_name(current_item(_menu));
	      return (1);
	    }
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

std::string			MenuFiles::getDir() const
{
  return (_dir);
}

std::string			MenuFiles::getRet()
{
  std::string			ret;

  ret = _ret;
  _ret.clear();
  return (ret);
}
