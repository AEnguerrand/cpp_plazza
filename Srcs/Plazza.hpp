/*
** plazza.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:28 2017 Quentin Metge
** Last update Wed Apr 19 10:56:08 2017 Quentin Metge
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

  enum class FileCiphered : int
  {
    DEFAULT = 0,
    NORMAL = 1,
    CAESAR = 2,
    XOR = 3
  };

  class File
  {
  public:
    File(void){}
    File(std::string _fileName);
    File(File const& other);
    File const& operator=(File other);
    ~File(void);

  public:
    std::string       fileName;
    std::ifstream     file;
    FileCiphered      ciphered = FileCiphered::DEFAULT;
  };

  class Order
  {
  public:
    Order(void){}
    Order(std::string _fileName, std::string type);
    ~Order(void){}

  public:
    File              file;
    std::string       type;
  };

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

#endif
