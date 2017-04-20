/*
** NamedPipe.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:54:09 2017 Antoine Dury
** Last update Thu Apr 20 15:04:18 2017 Antoine Dury
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string name)
{
  name = "/tmp/" + name + ".fifo";
  this->_fifo = name;
}

NamedPipe::~NamedPipe(void) {}

void            NamedPipe::create(void)
{
  if (mkfifo(this->_fifo.c_str(), 0644) != 0)
    throw Error("Unable to create a named pipe.");
}

void            NamedPipe::write(void *data, size_t size)
{
  std::fstream  file;

  file.open(this->_fifo, std::ios::out);
  file.write((char*)data, size);
  file.close();
}

void            *NamedPipe::read(void *data, size_t size)
{
  std::fstream  file;

  file.open(this->_fifo, std::ios::in);
  file.read((char*)data, size);
  file.close();
  unlink(this->_fifo.c_str());
  return (data);
}
