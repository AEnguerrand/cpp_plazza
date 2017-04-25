/*
** NamedPipe.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:28:06 2017 Antoine Dury
** Last update Tue Apr 25 11:42:46 2017 Antoine Dury
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
    virtual void        read(void*, size_t);

    const std::string&  getFifo(void) const;
    void                *getData(void) const;
    size_t              getSize(void) const;

  private:
    std::string         _fifo;
    void                *_data;
    size_t              _size;
};

std::fstream&           operator<<(std::fstream&, const NamedPipe&);
std::fstream&           operator>>(std::fstream& fs, const NamedPipe& np);

#endif
