/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:28 2017 Quentin Metge
** Last update Mon Apr 17 19:36:50 2017 Quentin Metge
*/

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

#include <iostream>

namespace plazza
{

  class Plazza
  {
  public:
    Plazza(void);
    Plazza(const int threadPoolSize);
    virtual ~Plazza(void);
  };

}

#endif
