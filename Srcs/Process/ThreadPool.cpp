/*
** ThreadPool.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ThreadPool.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 10:36:03 2017 Enguerrand Allamel
** Last update Wed Apr 19 10:36:03 2017 Enguerrand Allamel
*/

#include "ThreadPool.hpp"

plazza::ThreadPool::ThreadPool(size_t nbWorker)
{
  this->_mutex = new Mutex();
  for (size_t i = 0 ; i < nbWorker ; i++)
    {
      this->_worker.push_back(ThreadPoolWorker(&this->_orders, this->_mutex));
    }
}

plazza::ThreadPool::~ThreadPool()
{
  delete this->_mutex;
}

void plazza::ThreadPool::addOrder(Order order)
{
  this->_mutex->lock();
  this->_orders.push_back(order);
  this->_mutex->unlock();
}