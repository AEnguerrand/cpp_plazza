/*
** ProcessPlazza.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Wed Apr 19 17:49:39 2017 Enguerrand Allamel
*/

#include "ProcessPlazza.hpp"

/*
 * Function Scrapper
 */

static void	*scrapper(void *data)
{
  (void)data;
  std::cout << "Scrapper CALL IS GOOD" << std::endl;
  return (NULL);
}

plazza::ProcessPlazza::ProcessPlazza(std::list<Order> orders) :
	_orders(orders)
{
  this->_process = new Process();
  std::cout << "CTOR Process Plazza" << std::endl;
}

void plazza::ProcessPlazza::start()
{
  if (this->_process->isChild())
    {
      // REMOVE AFTER TEST
      for (auto it = this->_orders.begin(); it != this->_orders.end(); ++it)
	{
	  this->_threads.push_back(new Thread(&scrapper, static_cast<void *>(&(*it))));
	}

      for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
	{
	  (*it)->start();
	}
      std::cout << "Process Plazza: All run" << std::endl;
      for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
	{
	  (*it)->wait();
	}
      // END
    }
}

plazza::ProcessPlazza::~ProcessPlazza()
{
  delete this->_process;
  std::cout << "DTOR Process Plazza" << std::endl;
}