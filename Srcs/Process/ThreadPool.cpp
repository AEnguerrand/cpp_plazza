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

ThreadPool::ThreadPool(size_t nbWorker) :
	_condVar(new CondVar())
{
  for (size_t i = 0 ; i < nbWorker ; i++)
    {
      this->_worker.push_back(ThreadPoolWorker());
    }
}

ThreadPool::~ThreadPool()
{

}