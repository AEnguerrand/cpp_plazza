/*
** ProcessPlazza.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Tue Apr 25 10:36:46 2017 Quentin Metge
*/

#include "ProcessPlazza.hpp"

plazza::ProcessPlazza::ProcessPlazza(std::list<Order> orders, size_t poolSize) :
	_orders(orders),
	_poolSize(poolSize),
	_start(false)
{
  this->_id = 20;
  this->_process = new Process();
}

plazza::ProcessPlazza::~ProcessPlazza()
{
  // No kill process
  delete this->_process;
}

void plazza::ProcessPlazza::setId(size_t id)
{
  this->_id = id;
}

size_t plazza::ProcessPlazza::getId() const
{
  return this->_id;
}

void plazza::ProcessPlazza::start()
{
  this->_start = true;
  this->_process->start();
  if (this->_process->isChild())
    {
      ProcessChildPlazza processChildPlazza = ProcessChildPlazza(this->_orders, this->_poolSize, this->_id);
      processChildPlazza.run();
      exit(0);
    }
  else
    {
      // No wait end of processs
      // this->_process->wait();
    }
}