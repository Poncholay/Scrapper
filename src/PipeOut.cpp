//
// PipeOut.cpp for PipeOut in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:05:28 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 22:56:31 2016 guillaume wilmot
//

#include <unistd.h>
#include <fcntl.h>
#include "PipeOut.hh"
#include "CommunicationError.hh"

PipeOut::PipeOut(std::string path) : _path(path)
{
}

PipeOut::~PipeOut() {}

PipeOut::PipeOut(PipeOut const &src)
{
  _readFd = src.getReadFd();
}

PipeOut		&PipeOut::operator=(PipeOut const &src)
{
  if (this != &src)
    {
      _readFd = src.getReadFd();
    }
  return (*this);
}

void		PipeOut::destroy() const
{
  close(_readFd);
}

int		PipeOut::write(t_processState &)
{
  return (-1);
}

int			PipeOut::read(t_processState &state)
{
  int			ret;

  _readFd = (open(_path.c_str(), O_RDONLY));
  if (_readFd == -1)
    throw CommunicationError("Error: opening of a named pipe to read in it failed.");
  if ((ret = ::read(_readFd, &state, sizeof(t_processState))) == -1)
    std::cerr << "Error: Could not read in Pipe" << std::endl;
  destroy();
  return (ret);
}

int		PipeOut::getReadFd() const
{
  return (_readFd);
}

void		PipeOut::setReadFd(int const &newFd)
{
  _readFd = newFd;
}

int		PipeOut::getWriteFd() const
{
  return (-1);
}

void		PipeOut::setWriteFd(int const &)
{

}
