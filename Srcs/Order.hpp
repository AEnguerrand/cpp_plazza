/*
** Order.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/Order.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 23:29:34 2017 Enguerrand Allamel
** Last update Wed Apr 26 22:58:15 2017 Antoine Dury
*/

#ifndef CPP_PLAZZA_ORDER_HPP
#define CPP_PLAZZA_ORDER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "Error.hpp"

#define BUFFER_SIZE 4096

namespace plazza
{
  enum class TokenType : int
  {
    DEFAULT = 0,
    ORDER = 1
  };

  struct Order
  {
   public:
    char              fileName[BUFFER_SIZE];
    char              type[BUFFER_SIZE];
    char              regexp[BUFFER_SIZE];
  };
}

#endif //CPP_PLAZZA_ORDER_HPP
