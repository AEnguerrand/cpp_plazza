/*
** NamedPipe.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:54:09 2017 Antoine Dury
** Last update Tue Apr 18 16:21:26 2017 Antoine Dury
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string name)
{
  name = "/tmp/" + name;
  this->_name = name;
}

NamedPipe::~NamedPipe(void)
{
}

void        NamedPipe::createNP(void)
{
  if (mkfifo(this->_name.c_str(), 0644) != 0)
    throw Error("Unable to create a named pipe.");
}

void        NamedPipe::writeNP(std::string str)
{
  int       fd;

  if ((fd = open(this->_name.c_str(), O_WRONLY)) == -1)
    throw Error("Unable to open a named pipe.");
  write(fd, str.c_str(), strlen(str.c_str()));
  close(fd);
}

std::string NamedPipe::readNP(void)
{
  int       fd;
  char      str[256];

  if ((fd = open(this->_name.c_str(), O_RDONLY)) == -1)
    throw Error("Unable to open a named pipe.");
  read(fd, str, 256);
  printf("%s\n", str);
  close(fd);
  return (std::string(str));
}
