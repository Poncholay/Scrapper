//
// Pipes.cpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:46:45 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr 21 16:34:08 2016 guillaume wilmot
//

#include <unistd.h>
#include <sys/stat.h>
#include "Pipes.hpp"
#include "PipeOut.hh"
#include "PipeIn.hh"
#include "CommunicationError.hh"

Pipes::Pipes(int id) : _id(id)
{
  std::string	tmp;

  srand(time(NULL));
  for (int i = 0; i < 20 + rand() % 40; i++)
    tmp += rand() % 2 ? 48 + rand() % 9 : rand() % 2 ? 65 + rand() % 25 : 97 + rand() % 25;
  _path = std::string("./np") + std::to_string(_id) + tmp;
  if (mkfifo(_path.c_str(),
	     S_IRWXU | S_IRGRP | S_IWGRP) == -1)
    {
      unlink(_path.c_str());
      if (mkfifo(_path.c_str(),
		 S_IRWXU | S_IRGRP | S_IWGRP) == -1)
	throw CommunicationError("Error: creation of a named pipe failed.");
    }
  _out = new PipeOut(_path);
  _in = new PipeIn(_path);
}

Pipes::~Pipes()
{
  destroy();
}

int		Pipes::write(t_processState &state) const
{
  return (_in->write(state));
}

int		Pipes::read(t_processState &state) const
{
  return (_out->read(state));
}

int		Pipes::destroy() const
{
  delete _out;
  delete _in;
  unlink(_path.c_str());
  return (0);
}
