/*
** INamedPipe for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:04:19 2017 Antoine Dury
** Last update Thu Apr 20 14:47:03 2017 Antoine Dury
*/

#ifndef INAMEDPIPE_HPP
#define INAMEDPIPE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include "Error.hpp"

struct Test
{
  int nb;
  char str[0];
};

class INamedPipe
{
  public:
    virtual ~INamedPipe(void) {}

    virtual void        create(void) = 0;
    virtual void        write(void*, size_t) = 0;
    virtual void        *read(void*, size_t) = 0;
};

#endif
