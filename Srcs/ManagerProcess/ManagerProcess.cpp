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

plazza::ManagerProcess::ManagerProcess(size_t poolSize) :
	_poolSize(poolSize)
{
  std::cout << "CTOR ManagerProcess" << std::endl;
}

plazza::ManagerProcess::~ManagerProcess()
{
  std::cout << "DTOR ManagerProcess" << std::endl;
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
  size_t 	process_nb = 1 + std::ceil(this->_orders.size() / this->_poolSize);

  std::cout << "Nb Process: " << process_nb << std::endl;
  auto itOrderF = this->_orders.begin();
  auto itOrderL = this->_orders.begin();
  for (size_t i = 0; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
  for (size_t i = 0 ; i < process_nb ; i++)
    {
      std::list<Order> process_orders;
      process_orders.insert(process_orders.begin(), itOrderF, itOrderL);
      this->_processes.push_back(new ProcessPlazza(process_orders));
      itOrderF = itOrderL;
      for (size_t i = 0 ; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
    }
  for (auto it = this->_processes.begin() ; it != this->_processes.end() ; ++it)
    {
      (*it)->start();
    }
  for (auto it = this->_processes.begin() ; it != this->_processes.end() ; ++it)
    {
      delete (*it);
    }
  this->_processes.clear();
  this->_orders.clear();
}