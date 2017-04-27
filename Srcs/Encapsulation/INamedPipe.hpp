/*
** INamedPipe for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:04:19 2017 Antoine Dury
** Last update Wed Apr 26 16:15:13 2017 Antoine Dury
*/

#ifndef INAMEDPIPE_HPP
#define INAMEDPIPE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>

class INamedPipe
{
  public:
    virtual ~INamedPipe(void) {}

    virtual void        create(std::string) = 0;
    virtual void        writeNP(void*, size_t) = 0;
    virtual void        readNP(void*, size_t) = 0;
};

#endif
