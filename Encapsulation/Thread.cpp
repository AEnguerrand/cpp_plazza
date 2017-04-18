/*
** AThread.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 11:36:07 2017 Enguerrand Allamel
** Last update Mon Apr 10 11:36:07 2017 Enguerrand Allamel
*/

#include "Thread.hpp"

Thread::Thread(void *(*ptr_func)(void *), void *data)
{
  this->_data = data;
  this->_ptr_func = ptr_func;
  this->_status = IThread::STATUS::NOT_START;
}

IThread::STATUS Thread::getStatus() const
{
  return this->_status;
}

void Thread::start()
{
  pthread_create(&this->_thread, NULL, this->_ptr_func, this->_data);
  this->_status = IThread::STATUS::RUN;
}

void Thread::wait()
{
  pthread_join(this->_thread, NULL);
  this->_status = IThread::STATUS::DEAD;
}