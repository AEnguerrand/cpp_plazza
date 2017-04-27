/*
** ProcessChildPlazza.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessChildPlazza.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Apr 27 11:12:50 2017 Enguerrand Allamel
** Last update Thu Apr 27 11:12:50 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_PROCESSCHILDPLAZZA_HPP
#define CPP_PLAZZA_PROCESSCHILDPLAZZA_HPP

#include <functional>
#include <list>
#include "Order.hpp"
#include "Thread.hpp"
#include "Process.hpp"
#include "Scrapper.hpp"
#include "ThreadPool.hpp"

#define ONE_SEC        (1000000)

namespace plazza
{
  class ProcessChildPlazza
  {
   private:
    std::list<Order>	_orders;
    size_t 		_poolSize;
   public:
    ProcessChildPlazza(std::list<Order> orders, size_t poolSize);
    virtual ~ProcessChildPlazza();

    void run();
  };
}


#endif //CPP_PLAZZA_PROCESSCHILDPLAZZA_HPP
