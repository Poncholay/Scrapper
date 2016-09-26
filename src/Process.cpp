//
// Process.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:31:06 2016 guillaume wilmot
// Last update Sun Apr 24 23:10:26 2016 guillaume wilmot
//

#include <unistd.h>
#include <cstring>
#include "Process.hpp"

Process::Process(Com *com)
{
  _pid = 0;
  _com = com;
}

Process::~Process()
{
  delete _com;
}

int			Process::create(void *(*ptr)(void *), void *arg)
{
  void			*ret;

  if ((_pid = fork()) == 0)
    {
      ret = ptr(arg);
      exit(ret == NULL ? -1 : 0);
    }
  return (_pid == -1 ? -1 : 0);
}

bool			Process::checkAvailable() const
{
  t_processState	*state;
  bool			ret;

  state = new t_processState;
  memset(state, 0, sizeof(*state));
  state->state = FREE;
  try {
    *_com << *state;
    *_com >> *state;
  } catch (const CommunicationError &e)
    {
      delete state;
      return (false);
    }
  ret = state->free;
  delete state;
  return (ret);
}

void			Process::getStatus(int *arg) const
{
  t_processState	*state;

  state = new t_processState;
  memset(state, 0, sizeof(*state));
  state->state = STATE;
  try {
    *_com << *state;
    *_com >> *state;
    arg[0] = state->threads[0];
    arg[1] = state->threads[1];
    arg[2] = state->threads[2];
  } catch (const CommunicationError &e) {}
  delete state;
}

bool			Process::assign(const std::string &fileName, Information info) const
{
  t_processState	*state;

  state = new t_processState;
  memset(state, 0, sizeof(*state));
  state->free = 0;
  state->info = info;
  memset(state->fileName, 0, sizeof(state->fileName));
  std::strncpy(state->fileName, fileName.c_str(), std::strlen(fileName.c_str()));
  state->state = ASSIGN;
  try {
    *_com << *state;
    *_com >> *state;
  } catch (const CommunicationError &e)
    {
      delete state;
      return (false);
    }
  delete state;
  return (true);
}

Com			*Process::getCom() const
{
  return (_com);
}
