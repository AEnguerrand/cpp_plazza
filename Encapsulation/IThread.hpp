/*
** IThread.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/IThread.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 10:52:50 2017 Enguerrand Allamel
** Last update Tue Apr 18 10:52:50 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_ITHREAD_HPP
#define CPP_PLAZZA_ITHREAD_HPP

#include <iostream>
#include <pthread.h>

class IThread
{
 public:
  enum class STATUS {
    NOT_START,
    RUN,
    DEAD
  };

 public:
  virtual ~IThread() {}

  virtual IThread::STATUS getStatus() const = 0;
  virtual void start() = 0;
  virtual void wait() = 0;
};

#endif //CPP_PLAZZA_ITHREAD_HPP
