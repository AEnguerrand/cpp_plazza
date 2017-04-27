/*
** ProcessPlazza.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Thu Apr 27 12:27:10 2017 Quentin Metge
*/

#include "ProcessPlazza.hpp"

/*
 * Function Scrapper
 */

static void		*scrapper(void *data)
{
  plazza::Scrapper    scrapper(*static_cast<plazza::DataScrapper*>(data));
  return (NULL);
}

plazza::ProcessPlazza::ProcessPlazza(std::list<Order> orders, NamedPipe* np) :
	_orders(orders), _np(np)
{
  this->_process = new Process();
  std::cout << "CTOR Process Plazza" << std::endl;
}

plazza::ProcessPlazza::~ProcessPlazza()
{
  //delete this->_process;
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
     //this->_process->wait();
    }
}

void plazza::ProcessPlazza::processLoop()
{
  std::clock_t            c_start;
  bool                    end = true;
  plazza::DataScrapper    dataScrapper(this->_np);

  while (end)
    {
      std::cout << "PASS NOT END" << std::endl;
      for (auto it = this->_orders.begin(); it != this->_orders.end(); ++it)
	{
    dataScrapper.setOrder(*it);
	  this->_threads.push_back(new Thread(&scrapper, &dataScrapper));
	}
      for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
	{
	  (*it)->start();
	}
      std::cout << "--START--" << std::endl;
      for (auto it = this->_threads.begin(); it != this->_threads.end(); ++it)
	{
	  (*it)->wait();
	  this->_orders.pop_front();
	}
      std::cout << "--END--" << std::endl;
      c_start = std::clock();
      while (this->_orders.size() == 0 && ((std::clock() - c_start) < (ONE_SEC * 5)));
      if (this->_orders.size() == 0)
	end = false;

    }
}
