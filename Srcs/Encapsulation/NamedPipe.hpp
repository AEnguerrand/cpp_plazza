/*
** NamedPipe.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:28:06 2017 Antoine Dury
** Last update Thu Apr 20 14:47:09 2017 Antoine Dury
*/

#ifndef NAMEDPIPE_HPP
#define NAMEDPIPE_HPP

#include "INamedPipe.hpp"

class NamedPipe : public INamedPipe
{
  public:
    NamedPipe(std::string name);
    virtual ~NamedPipe(void);

    virtual void        create(void);
    virtual void        write(void*, size_t);
    virtual void        *read(void*, size_t);

  private:
    std::string         _fifo;
};

#endif
