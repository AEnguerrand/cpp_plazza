/*
** NamedPipe.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Encapsulation
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 13:28:06 2017 Antoine Dury
** Last update Tue Apr 18 14:19:12 2017 Antoine Dury
*/

#ifndef NAMEDPIPE_HPP
#define NAMEDPIPE_HPP

#include "INamedPipe.hpp"

class NamedPipe : public INamedPipe
{
  public:
    NamedPipe(std::string name);
    virtual ~NamedPipe(void);

    virtual void        write(std::string str);
    virtual std::string read(void);

  private:
    int                 _fd;
    std::string         _name;
    std::ofstream       _os;
    std::ifstream       _is;
};

#endif
