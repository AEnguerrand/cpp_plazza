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

/*
 * Function Scrapper
 */

static void		*scrapper(void *data)
{
  plazza::Order 	*order = static_cast<plazza::Order*>(data);

  plazza::Scrapper    	scrapper(order);
  return (NULL);
}

/*
 * Function threadPool
 */

static void			*threadPool(void *data)
{
  plazza::ThreadPoolWorker 	*tpw = static_cast<plazza::ThreadPoolWorker*>(data);
  plazza::Order 		order;

  while (!tpw->isHalt())
    {
      if (tpw->getStatus() == plazza::ThreadPoolWorker::STATUS::FREE ||
	  tpw->getStatus() == plazza::ThreadPoolWorker::STATUS::NOT_START)
	{
	  tpw->setStatus(plazza::ThreadPoolWorker::STATUS::RUN);
	  tpw->_mutex->lock();
	  if (tpw->_orders->empty())
	    {
	      tpw->_mutex->unlock();
	    }
	  else
	    {
	      order = *(tpw->_orders->begin());
	      tpw->_orders->pop_front();
	      tpw->_mutex->unlock();

	      scrapper(static_cast<void *>(&(order)));
	    }

	  tpw->setStatus(plazza::ThreadPoolWorker::STATUS::FREE);
	}
    }
  return (NULL);
}

/*
 * CTOR / DTOR
 */

plazza::ThreadPoolWorker::ThreadPoolWorker(std::list<Order> *orders, IMutex *mutex)
{
  this->_orders = orders;
  this->_mutex = mutex;
  this->_status = ThreadPoolWorker::STATUS::NOT_START;
  this->_halt = false;
  this->_thread = new Thread(&threadPool, static_cast<void *>(this));
  this->_thread->start();
}

plazza::ThreadPoolWorker::~ThreadPoolWorker()
{
  this->_status = ThreadPoolWorker::STATUS::HALT;
  delete this->_thread;
  this->_halt = true;
}

plazza::ThreadPoolWorker::STATUS plazza::ThreadPoolWorker::getStatus() const
{
  return this->_status;
}

void plazza::ThreadPoolWorker::setStatus(plazza::ThreadPoolWorker::STATUS status)
{
  this->_status = status;
}

bool plazza::ThreadPoolWorker::isHalt() const
{
  return this->_halt;
}

