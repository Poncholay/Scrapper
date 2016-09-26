//
// PipeIn.cpp for PipeIn in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:13:08 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:29:49 2016 Florian Saurs
//

#include <unistd.h>
#include <fcntl.h>
#include "PipeIn.hh"
#include "CommunicationError.hh"

PipeIn::PipeIn(std::string path) : _path(path) {}

PipeIn::~PipeIn() {}

PipeIn::PipeIn(PipeIn const &src)
{
  _writeFd = src.getWriteFd();
}

PipeIn		&PipeIn::operator=(PipeIn const &src)
{
  if (this != &src)
    _writeFd = src.getWriteFd();
  return (*this);
}

void		PipeIn::destroy() const
{
  close(_writeFd);
}

int		PipeIn::write(t_processState &state)
{
  _writeFd = (open(_path.c_str(), O_WRONLY));
  if (_writeFd == -1)
    throw CommunicationError("Error: opening of a named pipe to write in it failed.");
  if (::write(_writeFd, &state, sizeof(t_processState)) == -1)
    {
      destroy();
      std::cerr << "Error: Could not write in Pipe" << std::endl;
      return (-1);
    }
  destroy();
  return (0);
}

int		PipeIn::read(t_processState &)
{
  return (-1);
}

int		PipeIn::getWriteFd() const
{
  return (_writeFd);
}

void		PipeIn::setWriteFd(int const &newFd)
{
  _writeFd = newFd;
}

int		PipeIn::getReadFd() const
{
  return (-1);
}

void		PipeIn::setReadFd(int const &)
{

}
