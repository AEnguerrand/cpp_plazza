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

#include "Plazza.hpp"
#include "ICondVar.hpp"
#include "IThread.hpp"

class ThreadPoolWorker
{
 public:
  enum class STATUS
  {
    NOT_START,
    RUN
  };
 private:
  plazza::Order			_order;
  ThreadPoolWorker::STATUS 	_status;
 public:
  ThreadPoolWorker();
  virtual ~ThreadPoolWorker();

};


#endif //CPP_PLAZZA_THREADPOOLWORKER_HPP
