/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:28 2017 Quentin Metge
** Last update Tue Apr 18 12:45:01 2017 Quentin Metge
*/

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include "Error.hpp"

namespace plazza
{

  enum class OrderType
  {
    EMAIL_ADDRESS,
    IP_ADDRESS,
    PHONE_NUMBER
  };

  class Order
  {
  public:
    Order(void){}
    Order(std::string fileName, OrderType type);
    virtual ~Order(void);

  public:
    ofstream    file;
    OrderType   type;
  };

  class Plazza
  {
  public:
    Plazza(void){}
    Plazza(const int poolSize);
    virtual ~Plazza(void){}

  public:
    size_t      getPoolSize(void) const;

  private:
    size_t              _poolSize;
    std::list<Order>    _orderList;
  };

}

#endif
