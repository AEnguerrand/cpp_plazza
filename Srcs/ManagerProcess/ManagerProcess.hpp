/*
** ManagerProcess.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ManagerProcess.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:30:25 2017 Enguerrand Allamel
** Last update Wed Apr 19 17:30:25 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_MANAGERPROCESS_HPP
#define CPP_PLAZZA_MANAGERPROCESS_HPP

#include <iterator>
#include <cmath>
#include <list>
#include "Order.hpp"
#include "ProcessPlazza.hpp"

namespace plazza {
  class ManagerProcess
  {
   private:
    std::list<Order>		_orders;
    std::list<ProcessPlazza *>	_processes;
    size_t 			_poolSize;
   public:
    ManagerProcess(size_t poolSize);
    virtual ~ManagerProcess();

    void	addOrder(std::list<Order> orders);
    void	dispatch();
  };
}


#endif //CPP_PLAZZA_MANAGERPROCESS_HPP
