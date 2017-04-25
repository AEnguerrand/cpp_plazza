/*
** INamedPipe for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:04:19 2017 Antoine Dury
** Last update Tue Apr 25 11:37:21 2017 Antoine Dury
*/

#ifndef INAMEDPIPE_HPP
#define INAMEDPIPE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include "Error.hpp"

class INamedPipe
{
  public:
    virtual ~INamedPipe(void) {}

    virtual void        create(void) = 0;
    virtual void        write(void*, size_t) = 0;
    virtual void        read(void*, size_t) = 0;
};

#endif
