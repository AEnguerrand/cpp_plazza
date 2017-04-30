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

/*
 * Function check is Finish
 */
void			*processInfoPipe(void *data)
{
  plazza::ProcessManagerInfo* pmi = static_cast<plazza::ProcessManagerInfo*>(data);
  NamedPipe   		np("processInfoPipe");
  plazza::ProcessInfo	processInfo;

  (void)data;
  np.create("READ");
  while (true)
    {
      memset(&processInfo, 0, sizeof(processInfo));
      np.readNP(&processInfo, sizeof(processInfo));
      if (processInfo.type == 20)
	{
	  if (processInfo.isEmpty)
	    pmi->nbIsEmpty += 1;
	}
    }
  return (NULL);
}

/*
 * CTOR / DTOR
 */
plazza::ManagerProcess::ManagerProcess(size_t const poolSize) :
	_poolSize(poolSize * 2)
{
  this->_processInfos.nbIsEmpty = 0;
  this->_c_start = std::clock();
}

plazza::ManagerProcess::~ManagerProcess()
{
  if (!this->_processes.empty())
    {
      for (auto it = this->_processes.begin() ; it != this->_processes.end() ; ++it)
	delete (*it);
    }
}

void plazza::ManagerProcess::addOrder(std::list<Order> orders)
{
  for (auto it = orders.begin() ; it != orders.end() ; ++it)
    this->_orders.push_back(*(it));
  this->dispatch();
}

void 		plazza::ManagerProcess::dispatch()
{
  size_t 			process_nb = 1 + std::ceil(this->_orders.size() / this->_poolSize);

  auto itOrderF = this->_orders.begin();
  auto itOrderL = this->_orders.begin();
  this->_status.orders += this->_orders.size();
  for (size_t i = 0; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
  for (size_t i = 0 ; i < process_nb ; i++)
    {
      std::list<Order> process_orders;
      process_orders.insert(process_orders.begin(), itOrderF, itOrderL);
      ProcessPlazza *processPlazza = new ProcessPlazza(process_orders, this->_poolSize);
      processPlazza->start();
      this->_processes.push_back(processPlazza);
      this->_status.process += 1;
      this->_status.threads += this->_poolSize / 2;
      this->_status.tasks += this->_poolSize;
      itOrderF = itOrderL;
      for (size_t i = 0 ; itOrderL != this->_orders.end() && i < this->_poolSize ; ++itOrderL);
    }
  this->_orders.clear();
}

bool plazza::ManagerProcess::isFinish()
{
  if (this->_processInfos.nbIsEmpty < this->_processes.size() &&
	  (std::clock() - this->_c_start) < (ONE_SEC))
    return false;
  return true;
}

std::list<plazza::Order> 		plazza::ManagerProcess::getOrders(void) const{
	return (this->_orders);
}

void plazza::ManagerProcess::startProcessInfoPipe()
{
  IThread             *thread = new Thread(&processInfoPipe, &this->_processInfos);

  thread->start();
  delete thread;
}
