/*
** AThread.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 11:36:07 2017 Enguerrand Allamel
** Last update Tue Apr 25 10:20:28 2017 Antoine Dury
*/

#include "Thread.hpp"

Thread::Thread(void *(*ptr_func)(void *), void *data)
{
  this->_data = data;
  this->_ptr_func = ptr_func;
  this->_status = IThread::STATUS::NOT_START;
}

Thread::~Thread()
{
}

IThread::STATUS Thread::getStatus() const
{
  return this->_status;
}

void Thread::start()
{
  if (pthread_create(&this->_thread, NULL, this->_ptr_func, this->_data) != 0)
    throw Error("Thread: Fail start.");
  this->_status = IThread::STATUS::RUN;
}

void Thread::wait()
{
  if (pthread_join(this->_thread, NULL) != 0)
    throw Error("Thread: Fail wait.");
  this->_status = IThread::STATUS::DEAD;
}
