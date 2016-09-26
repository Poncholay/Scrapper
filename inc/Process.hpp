//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Sun Apr 24 23:10:30 2016 guillaume wilmot
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include "Com.hpp"

class		Process
{
private:
  pid_t			_pid;
  Com			*_com;

public:
  Process(Com *);
  ~Process();

  pid_t			getPid() const {return (_pid);}
  int			create(void *(*)(void *), void *);
  bool			checkAvailable() const;
  bool			assign(const std::string &, Information) const;
  Com			*getCom() const;
  void			getStatus(int *) const;
};

typedef struct		s_processArgs {
  int			nbThread;
  Com			*com;
}			t_processArgs;

#endif /* !PROCESS_HPP_ */
