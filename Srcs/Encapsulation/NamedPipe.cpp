/*
** NamedPipe.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:54:09 2017 Antoine Dury
** Last update Wed Apr 26 23:06:21 2017 Antoine Dury
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string name)
{
  name = "/tmp/" + name + ".fifo";
  this->_fifo = name;
}

NamedPipe::~NamedPipe(void)
{
  unlink(this->_fifo.c_str());
  close(this->_fd);
}

void                NamedPipe::create(std::string action)
{
  mkfifo(this->_fifo.c_str(), 0644);
  if (action == "WRITE")
    this->_fd = open(this->_fifo.c_str(), O_WRONLY);
  else if (action == "READ")
    this->_fd = open(this->_fifo.c_str(), O_RDONLY | O_NONBLOCK);
}

void                NamedPipe::writeNP(void *data, size_t size)
{
  write(this->_fd, reinterpret_cast<char*>(data), size);
}

void                NamedPipe::readNP(void *data, size_t size)
{
  read(this->_fd, reinterpret_cast<char*>(data), size);
}
