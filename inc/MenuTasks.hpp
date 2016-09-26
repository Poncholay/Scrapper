//
// MenuTasks.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 04:44:42 2016 guillaume wilmot
// Last update Sun Apr 24 23:26:43 2016 guillaume wilmot
//

#ifndef MENUTASKS_HPP_
# define MENUTASKS_HPP_

# include <vector>
# include "Menu.hpp"
# include "Core.hpp"

class		MenuTasks : public Menu {
public:
  MenuTasks(Core *);
  ~MenuTasks();

  int		init(const std::vector<std::string> &);
  int		initWindow();
  void		draw() const;
  void		free();
  int		events();
  void		setTasks();
  std::string	getRet();

private:
  ITEM				**_items;
  unsigned int			_nbItem;
  std::string			_ret;
  std::vector<std::string>	_choices;
};

#endif /* !MENU_TASKS */
