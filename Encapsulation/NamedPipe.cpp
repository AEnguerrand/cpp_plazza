/*
** NamedPipe.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:54:09 2017 Antoine Dury
** Last update Tue Apr 18 14:20:34 2017 Antoine Dury
*/

#include "NamedPipe.hpp"

NamedPipe::NamedPipe(std::string name)
{
  if (mkfifo(name.c_str(), 0644) != 0)
    throw Error("Unable to create a named pipe.");
}

NamedPipe::~NamedPipe(void)
{
}

void        NamedPipe::write(std::string str)
{
  (void)str;
}

std::string NamedPipe::read(void)
{
  return (NULL);
}
