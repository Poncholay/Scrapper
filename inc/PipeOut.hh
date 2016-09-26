//
// PipeOut.hh for PipeOut in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:07:10 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:50:43 2016 Florian Saurs
//

#ifndef PIPEOUT_HH_
# define PIPEOUT_HH_

# include "IPipe.hpp"

class		PipeOut : public IPipe
{
public:
  PipeOut(std::string path);
  ~PipeOut();
  PipeOut(PipeOut const &);
  PipeOut	&operator=(PipeOut const &);
  void		destroy() const;
  int		write(t_processState &);
  int		read(t_processState &);
  int		getReadFd() const;
  int		getWriteFd() const;
  void		setReadFd(int const &);
  void		setWriteFd(int const &);
private:
  fd_set	_readSelect;
  int		_readFd;
  std::string	_path;
};

#endif /* !PIPEOUT_HH_ */
