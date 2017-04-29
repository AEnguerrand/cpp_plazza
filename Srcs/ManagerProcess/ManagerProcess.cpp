/*
** ManagerProcess.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ManagerProcess.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:30:25 2017 Enguerrand Allamel
** Last update Wed Apr 19 17:30:25 2017 Enguerrand Allamel
*/

#include "ManagerProcess.hpp"

plazza::ManagerProcess::ManagerProcess(size_t const poolSize) :
	_poolSize(poolSize * 2)
{
  this->_c_start = std::clock();
}

plazza::ManagerProcess::~ManagerProcess()
{
  for (auto it = this->_processes.begin() ; it != this->_processes.end() ; ++it)
    {
      delete (*it);
    }
}

void plazza::ManagerProcess::addOrder(std::list<Order> orders)
{
  for (auto it = orders.begin() ; it != orders.end() ; ++it)
    {
      this->_orders.push_back(*(it));
    }
  this->dispatch();
}

void 		plazza::ManagerProcess::dispatch()
{
  size_t 			process_nb = 1 + std::ceil(this->_orders.size() / this->_poolSize);

  auto itOrderF = this->_orders.begin();
  auto itOrderL = this->_orders.begin();
  for (size_t i = 0; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
  for (size_t i = 0 ; i < process_nb ; i++)
    {
      std::list<Order> process_orders;
      process_orders.insert(process_orders.begin(), itOrderF, itOrderL);
      ProcessPlazza *processPlazza = new ProcessPlazza(process_orders, this->_poolSize);
      processPlazza->start();
      this->_processes.push_back(processPlazza);
      itOrderF = itOrderL;
      for (size_t i = 0 ; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
    }
  this->_orders.clear();
}

bool plazza::ManagerProcess::isFinish()
{
  if ((std::clock() - this->_c_start) < (ONE_SEC * 1))
    return false;
  return true;
}

std::list<plazza::Order> 		plazza::ManagerProcess::getOrders(void) const{
	return (this->_orders);
}
