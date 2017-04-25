/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:28 2017 Quentin Metge
** Last update Tue Apr 25 14:08:38 2017 Antoine Dury
*/

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include "Error.hpp"
#include "Order.hpp"
#include "ManagerProcess.hpp"

namespace plazza
{

  class Plazza
  {
  public:
    Plazza(void){}
    Plazza(const int poolSize);
    ~Plazza(void){}

  public:
    TokenType   getTypeOfToken(std::string token);
    void        getNextLine(std::string buffer);
    void        mainLoop(void);

  public:
    void        displayOrderList(void);

  public:
    size_t                    getPoolSize(void) const;
    std::vector<std::string>  getOrdersType(void) const;

  private:
    size_t                    _poolSize;
    std::vector<std::string>  _ordersType;
    std::list<Order>          _orderList;
  };

}

void *createDisplay(void*);

#endif
