/*
** NamedPipe.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:28:06 2017 Antoine Dury
** Last update Thu Apr 27 16:32:19 2017 Antoine Dury
*/

#ifndef NAMEDPIPE_HPP
#define NAMEDPIPE_HPP

#include "INamedPipe.hpp"

class NamedPipe : public INamedPipe
{
  public:
    NamedPipe(void);
    NamedPipe(std::string name);
    virtual ~NamedPipe(void);

    virtual void        create(std::string);
    virtual void        writeNP(void*, size_t);
    virtual void        readNP(void*, size_t);
    void                destroy(void);

  private:
    std::string         _fifo;
    int                 _fd;
};
#endif
