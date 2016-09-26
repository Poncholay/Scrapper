//
// Gui.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Apr 17 19:59:02 2016 guillaume wilmot
// Last update Sun Apr 24 23:24:40 2016 guillaume wilmot
//

#include <cstring>
#include <curses.h>
#include <signal.h>
#include <algorithm>
#include <unistd.h>
#include <signal.h>
#include "Gui.hpp"
#include "Thread.hpp"
#include "Core.hpp"
#include "Parsing.hpp"



Gui::Gui()
{
  _menuFiles = NULL;
}

Gui::~Gui()
{
  endwin();
  if (_menuFiles)
    delete _menuFiles;
}

void				Gui::handleResize()
{
  endwin();
  refresh();
  clear();
}

void				Gui::init(Core *core)
{
  _core = core;
  _menuFiles = new MenuFiles(core);
  _menuTasks = new MenuTasks(core);
  initscr();
  start_color();
  timeout(1000);
  noecho();
  curs_set(0);
  init_pair(1, COLOR_BLACK, COLOR_CYAN);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
}

void				Gui::changeDir(std::string &path, DIR **dir) const
{
  if (chdir(path.c_str()) == -1)
    return;
  path = "./";
  if ((*dir = opendir(path.c_str())) == NULL)
    {
      std::cerr << "Cannot open folder" << std::endl;
      return ;
    }
}

void				Gui::startMenu(Communication com)
{
  std::vector<std::string>	choices;
  DIR                           *dir = NULL;
  struct dirent                 **rd;
  int				ret;
  std::string			path = "./";

  while (1)
    {
      changeDir(path, &dir);
      if ((ret = scandir(".", &rd, 0, versionsort)) >= 0)
	for (int i = 0; i < ret; i++)
	  if ((std::string(rd[i]->d_name).at(0) != 'n' || std::string(rd[i]->d_name).at(1) != 'p') && std::string(rd[i]->d_name) != ".")
	    choices.push_back(std::string(rd[i]->d_name));
      std::sort(choices.begin(), choices.end());
      if (_menuFiles->init(choices) == -1 ||
	  _menuFiles->initWindow() == -1)
	return ;
      _menuFiles->draw();
      closedir(dir);
      if ((ret = _menuFiles->events()) == -1)
	return ;
      if (ret == 1)
	path = reinterpret_cast<MenuFiles *>(_menuFiles)->getDir();
      else if (ret != 2)
	{
	  if (_menuTasks->init(choices) == -1 ||
	      _menuTasks->initWindow() == -1)
	    return ;
	  _menuTasks->draw();
	  if ((ret = _menuTasks->events()) == 0)
	    {
	      _order += _menuFiles->getRet() + _menuTasks->getRet();
	      Parsing			parser;
	      std::vector<std::string>	command;
	      command.push_back(_order);
	      parser.parseCommandLine(&command, _core, com);
	      _order.clear();
	    }
	}
      _menuFiles->free();
      choices.clear();
    }
}
