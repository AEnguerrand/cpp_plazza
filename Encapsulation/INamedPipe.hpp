/*
** INamedPipe for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:04:19 2017 Antoine Dury
** Last update Tue Apr 18 14:03:13 2017 Antoine Dury
*/

#ifndef INAMEDPIPE_HPP
#define INAMEDPIPE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "Error.hpp"

class INamedPipe
{
  public:
    virtual ~INamedPipe(void) {}

    virtual void        write(std::string) = 0;
    virtual std::string read(void) = 0;
};

#endif
