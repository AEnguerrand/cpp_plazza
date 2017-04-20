/*
** Scrapper.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:29 2017 Quentin Metge
** Last update Thu Apr 20 16:10:42 2017 Quentin Metge
*/

#ifndef SCRAPPER_HPP
# define SCRAPPER_HPP

#include <regex>
#include "Order.hpp"

namespace plazza
{

  class Scrapper
  {
  public:
    Scrapper(void){};
    Scrapper(Order* order);
    virtual ~Scrapper(void);

  public:
    void          initBuffer(void);

  public:
    bool          scpNormal(void);
    bool          scpXor(void);
    bool          scpCaesar(void);

  private:
    Order*        _order;
    std::string   _buffer = "";

  private:
    std::vector<std::function<bool (void)>> _scrapperFct;
  };

}

#endif