/*
** ThreadPoolWorker.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ThreadPoolWorker.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 11:35:08 2017 Enguerrand Allamel
** Last update Wed Apr 19 11:35:08 2017 Enguerrand Allamel
*/

#include "ThreadPoolWorker.hpp"

ThreadPoolWorker::ThreadPoolWorker()
{
  this->_status = ThreadPoolWorker::STATUS::NOT_START;
}

ThreadPoolWorker::~ThreadPoolWorker()
{

}