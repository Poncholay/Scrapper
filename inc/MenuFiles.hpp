//
// MenuFiles.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 04:44:42 2016 guillaume wilmot
// Last update Sun Apr 24 23:26:50 2016 guillaume wilmot
//

#ifndef MENUFILES_HPP_
# define MENUFILES_HPP_

# include "Menu.hpp"
# include "Core.hpp"

class		MenuFiles : public Menu {
public:
  MenuFiles(Core *);
  ~MenuFiles();

  int		init(const std::vector<std::string> &);
  int		initWindow();
  void		draw() const;
  void		free();
  int		events();
  void		setFiles();
  std::string	getDir() const;
  std::string	getRet();
  void		printThreads() const;
  void		printDirectory(int) const;
  void		printHelp(int) const;

private:
  ITEM		**_items;
  unsigned int	_nbItem;
  std::string	_ret;
  std::string	_dir;
};

#endif /* !MENU_FILES */
