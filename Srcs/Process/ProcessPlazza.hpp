/*
** ProcessPlazza.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Thu Apr 20 16:04:55 2017 Quentin Metge
*/

#ifndef CPP_PLAZZA_PROCESSPLAZZA_HPP
#define CPP_PLAZZA_PROCESSPLAZZA_HPP

#include <functional>
#include <list>
#include "Thread.hpp"
#include "Process.hpp"
#include "Order.hpp"
#include "Scrapper.hpp"

namespace plazza
{
  class ProcessPlazza
  {
   private:
    std::list<Order>	_orders;
    std::list<IThread *>_threads;
    IProcess		*_process;
   public:
    ProcessPlazza(std::list<Order> orders);
    virtual ~ProcessPlazza();

    void	start();
  };
}


#endif //CPP_PLAZZA_PROCESSPLAZZA_HPP
