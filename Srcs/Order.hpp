/*
** Order.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/Order.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 23:29:34 2017 Enguerrand Allamel
** Last update Thu Apr 20 15:49:33 2017 Quentin Metge
*/

#ifndef CPP_PLAZZA_ORDER_HPP
#define CPP_PLAZZA_ORDER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Error.hpp"

namespace plazza
{
  enum class TokenType : int
  {
    DEFAULT = 0,
    ORDER = 1
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
    std::string       name;
    std::ifstream     ss;
  };

  class Order
  {
   public:
    Order(void){}
    Order(std::string _fileName, std::string type);
    ~Order(void){}

   public:
    void              display(void);

   public:
    File              file;
    std::string       type;
    std::string       regexp;
  };
}

#endif //CPP_PLAZZA_ORDER_HPP
