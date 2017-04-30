/*
** ManagerProcess.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ManagerProcess.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:31:25 2017 Enguerrand Allamel
** Last update Fri Apr 28 13:42:49 2017 Antoine Dury
*/

#ifndef CPP_PLAZZA_MANAGERPROCESS_HPP
#define CPP_PLAZZA_MANAGERPROCESS_HPP

#include <iterator>
#include <cmath>
#include <list>
#include "ProcessPlazza.hpp"
#include "Scrapper.hpp"
#include "ProcessInfo.hpp"

namespace plazza {

  struct    Status
  {
    size_t  tasks = 0;
    size_t  process = 0;
    size_t  threads = 0;
    size_t  orders = 0;
  };

  struct ProcessManagerInfo
  {
    size_t nbIsEmpty = 0;
  };

  class ManagerProcess
  {
   private:
    std::list<Order>		        _orders;
    std::list<ProcessPlazza *>		_processes;
    size_t 			       	_poolSize;
    std::clock_t  			_c_start;

   public:
    ManagerProcess(void){}
    ManagerProcess(size_t const poolSize);
    virtual ~ManagerProcess();

    void	addOrder(std::list<Order> orders);
    void	dispatch();

    void	startProcessInfoPipe();

    bool	isFinish();
  public:
    std::list<Order>  	getOrders(void) const;
    Status            	_status;
    bool 		_isFinish;
    ProcessManagerInfo	_processInfos;
  };
}


#endif //CPP_PLAZZA_MANAGERPROCESS_HPP
