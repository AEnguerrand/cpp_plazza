/*
** ProcessChildPlazza.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessChildPlazza.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Apr 27 11:12:50 2017 Enguerrand Allamel
** Last update Thu Apr 27 11:12:50 2017 Enguerrand Allamel
*/

#include "ProcessChildPlazza.hpp"

plazza::ProcessChildPlazza::ProcessChildPlazza(std::list<Order> orders, size_t poolSize) :
	_orders(orders),
	_poolSize(poolSize)
{
}

plazza::ProcessChildPlazza::~ProcessChildPlazza()
{
}

void plazza::ProcessChildPlazza::run()
{
  std::clock_t  c_start;
  bool 		end = true;
  ThreadPool	thPool(this->_poolSize);

  while (end)
    {
      for (auto it = this->_orders.begin(); it != this->_orders.end(); ++it)
	thPool.addOrder(*it);
      this->_orders.clear();
      c_start = std::clock();
      while (!thPool.isEmpty() || ((std::clock() - c_start) < (ONE_SEC * 5)));
      if (thPool.isEmpty())
	end = false;
    }
}