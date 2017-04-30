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

plazza::ProcessChildPlazza::ProcessChildPlazza(std::list<Order> orders, size_t poolSize, size_t id) :
	_orders(orders),
	_poolSize(poolSize),
	_id(id)
{
  this->_lastNbOrders = orders.size();
}

plazza::ProcessChildPlazza::~ProcessChildPlazza()
{
}

void plazza::ProcessChildPlazza::run()
{
  std::clock_t  c_start;
  bool 		end = true;
  bool 		infoSend = false;
  ThreadPool	thPool(this->_poolSize);
  NamedPipe   	np("processInfoPipe");

  while (end)
    {
      for (auto it = this->_orders.begin(); it != this->_orders.end(); ++it)
	thPool.addOrder(*it);
      this->_orders.clear();
      c_start = std::clock();
      while (!thPool.isEmpty() || ((std::clock() - c_start) < (ONE_SEC * 5)))
	{
	  if (thPool.isEmpty() && !infoSend)
	    {
	      this->processInfoPipe(np);
	      infoSend = true;
	      end = false;
	    }
	}
    }
}
void plazza::ProcessChildPlazza::setId(size_t id)
{
  this->_id = id;
}

size_t plazza::ProcessChildPlazza::getId() const
{
  return this->_id;
}


void plazza::ProcessChildPlazza::processInfoPipe(NamedPipe np) const
{
  plazza::ProcessInfo	processInfo;

  np.create("WRITE");
  memset(&processInfo, 0, sizeof(processInfo));
  processInfo.type = 20;
  processInfo.orderNb = 1;
  processInfo.id = this->_id;
  processInfo.orderNb = 12;
  processInfo.isEmpty = true;
  processInfo.isFull = false;
  np.writeNP(&processInfo, sizeof(processInfo));
}