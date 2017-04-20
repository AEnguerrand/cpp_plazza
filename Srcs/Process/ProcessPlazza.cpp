/*
** ProcessPlazza.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Thu Apr 20 14:26:56 2017 Quentin Metge
*/

#include "ProcessPlazza.hpp"

/*
 * Function Scrapper
 */

static void		*scrapper(void *data)
{
  plazza::Order 	*order = static_cast<plazza::Order*>(data);

  order->display();
  return (NULL);
}

plazza::ProcessPlazza::ProcessPlazza(std::list<Order> orders) :
	_orders(orders)
{
  this->_process = new Process();
  std::cout << "CTOR Process Plazza" << std::endl;
}

plazza::ProcessPlazza::~ProcessPlazza()
{
  delete this->_process;
  std::cout << "DTOR Process Plazza" << std::endl;
}

void plazza::ProcessPlazza::start()
{
  std::cout << "Process Plazza: Nb Orders: " << this->_orders.size() << std::endl;

  this->_process->start();
  if (this->_process->isChild())
    {
      this->processLoop();
      exit(0);
    }
  else
    {
      this->_process->wait();
    }
}

void plazza::ProcessPlazza::processLoop()
{
  for (auto it = this->_orders.begin(); it != this->_orders.end(); ++it)
    {
      this->_threads.push_back(new Thread(&scrapper, static_cast<void *>(&(*it))));
    }
  for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
    {
      (*it)->start();
    }
  for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
    {
      (*it)->wait();
    }
}

