/*
** ThreadPool.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ThreadPool.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 10:36:03 2017 Enguerrand Allamel
** Last update Wed Apr 19 10:36:03 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_THREADPOOL_HPP
#define CPP_PLAZZA_THREADPOOL_HPP

#include "Order.hpp"
#include "CondVar.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ThreadPoolWorker.hpp"

namespace plazza
{
  class ThreadPool
  {

   private:
    std::list<ThreadPoolWorker *> _worker;
    std::list<Order> 		_orders;
    IMutex 			*_mutex;
    //ICondVar			*_condVar;
   public:
    ThreadPool(size_t nbWorker);
    virtual ~ThreadPool();

    void 	addOrder(Order order);
    bool 	isEmpty();
  };
}


#endif //CPP_PLAZZA_THREADPOOL_HPP
