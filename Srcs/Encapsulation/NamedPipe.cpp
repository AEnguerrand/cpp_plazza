/*
** NamedPipe.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:54:09 2017 Antoine Dury
** Last update Tue Apr 25 10:22:32 2017 Antoine Dury
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string name)
{
  name = "/tmp/" + name + ".fifo";
  this->_fifo = name;
}

NamedPipe::~NamedPipe(void) {}

void                NamedPipe::create(void)
{
  if (mkfifo(this->_fifo.c_str(), 0644) != 0)
    throw Error("Unable to create a named pipe.");
}

void                NamedPipe::write(void *data, size_t size)
{
  std::fstream      fs;

  this->_data = data;
  this->_size = size;
  fs << *this;
}

void                *NamedPipe::read(void *data, size_t size)
{
  std::fstream      fs;

  this->_data = data;
  this->_size = size;
  fs >> *this;
  return (data);
}

const std::string&  NamedPipe::getFifo(void) const
{
  return (this->_fifo);
}

void                *NamedPipe::getData(void) const
{
  return (this->_data);
}

size_t              NamedPipe::getSize(void) const
{
  return (this->_size);
}

std::fstream&       operator<<(std::fstream& fs, const NamedPipe& np)
{
  fs.open(np.getFifo(), std::ios::out | std::ios::binary);
  fs.write((char*)np.getData(), np.getSize());
  fs.close();
  return (fs);
}

std::fstream&       operator>>(std::fstream& fs, const NamedPipe& np)
{
  fs.open(np.getFifo(), std::ios::in | std::ios::binary);
  fs.read((char*)np.getData(), np.getSize());
  fs.close();
  unlink(np.getFifo().c_str());
  return (fs);
}
