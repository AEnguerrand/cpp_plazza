/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:28 2017 Quentin Metge
** Last update Tue Apr 18 17:17:13 2017 Quentin Metge
*/

#ifndef PLAZZA_HPP_
# define PLAZZA_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include "Error.hpp"

namespace plazza
{

  enum class TokenType : int
  {
    DEFAULT = 0,
    ORDER = 1
  };

  class Order
  {
  public:
    Order(void){}
    Order(std::string fileName, std::string type);
    Order(Order const& other);
    Order const& operator=(Order const& other);

    virtual ~Order(void);

  public:
    std::string       fileName;
    std::ifstream     file;
    std::string       type;
  };

  class Plazza
  {
  public:
    Plazza(void){}
    Plazza(const int poolSize);
    virtual ~Plazza(void){}

  public:
    TokenType   getTypeOfToken(std::string token);
    void        mainLoop(void);

  public:
    size_t                    getPoolSize(void) const;
    std::vector<std::string>  getOrdersType(void) const;

  private:
    size_t                    _poolSize;
    std::vector<std::string>  _ordersType;
    std::list<Order>          _orderList;
  };

}

#endif
