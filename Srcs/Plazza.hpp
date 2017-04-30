/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 20:27:28 2017 Quentin Metge
** Last update Sun Apr 30 16:19:04 2017 Quentin Metge
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

  enum Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

  class Plazza
  {
  public:
    Plazza(void){}
    Plazza(const size_t poolSize);
    ~Plazza(void);

  public:
    TokenType   getTypeOfToken(std::string const& token);
    void        getNextLine(std::string const& buffer);
    void        sendLine(std::string const& buffer);
    void        mainLoop(void);

  public:
    void        displayOrderList(void) const;

  public:
    size_t                    getPoolSize(void) const;
    std::vector<std::string>  getOrdersType(void) const;
    std::list<Order>          getOrderList(void) const;
    ManagerProcess            getManagerProcess(void) const;
    Status                    getStatus(void) const;
    void                      clearOrderList(void);

  private:
    size_t                    _poolSize;
    std::vector<std::string>  _ordersType;
    std::list<Order>          _orderList;
    ManagerProcess            _managerProcess;
  };

}

void *createDisplay(void*);

#endif
