//
// ICondVar.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:46 2016 guillaume wilmot
// Last update Tue Apr 19 17:48:05 2016 Florian Saurs
//

#ifndef ICONDVAR_HPP_
# define ICONDVAR_HPP_

class ICondVar
{
public:
  virtual ~ICondVar() {}
  virtual void wait() = 0;
  virtual void signal() = 0;
  virtual void broadcast() = 0;
};

#endif /* !ICONDVAR_HPP_ */
