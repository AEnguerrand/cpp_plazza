/*
** Scrapper.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:29 2017 Quentin Metge
** Last update Thu Apr 20 14:59:29 2017 Quentin Metge
*/

#ifndef SCRAPPER_HPP
# define SCRAPPER_HPP

#include "Order.hpp"

namespace plazza
{

  class Scrapper
  {
  public:
    Scrapper(Order const& order);
    virtual ~Scrapper(void);

  private:
    Order   _order;
  };

}

#endif
