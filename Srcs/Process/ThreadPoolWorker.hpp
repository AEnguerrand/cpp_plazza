/*
** ThreadPoolWorker.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ThreadPoolWorker.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 11:35:08 2017 Enguerrand Allamel
** Last update Wed Apr 19 11:35:08 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_THREADPOOLWORKER_HPP
#define CPP_PLAZZA_THREADPOOLWORKER_HPP

#include <list>
#include "Order.hpp"
#include "IMutex.hpp"
#include "ICondVar.hpp"
#include "Thread.hpp"
#include "Scrapper.hpp"

namespace plazza
{
  class ThreadPoolWorker
  {
   public:
    enum class STATUS
    {
      NOT_START,
      RUN,
      FREE,
      HALT,
    };

   private:
    ThreadPoolWorker::STATUS 	_status;
    IThread 			*_thread;
   public:
    IMutex 			*_mutex;
    std::list<Order> 		*_orders;
    bool 			_halt;

   public:
    ThreadPoolWorker(std::list<Order> *orders, IMutex *mutex);

    virtual ~ThreadPoolWorker();

    void setStatus(ThreadPoolWorker::STATUS status);

    ThreadPoolWorker::STATUS getStatus() const;

    bool isHalt() const;
  };
}

#endif //CPP_PLAZZA_THREADPOOLWORKER_HPP
