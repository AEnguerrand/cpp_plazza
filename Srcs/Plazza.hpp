/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 20:27:28 2017 Quentin Metge
** Last update Thu Apr 27 18:21:35 2017 Quentin Metge
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
    Plazza(const size_t poolSize);
    ~Plazza(void);

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
    ManagerProcess            _managerProcess;
  };

}

void *createDisplay(void*);

#endif
