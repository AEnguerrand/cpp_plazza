/*
** ProcessPlazza.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessPlazza.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Apr 19 17:49:39 2017 Enguerrand Allamel
** Last update Thu Apr 27 12:26:47 2017 Quentin Metge
*/

#ifndef CPP_PLAZZA_PROCESSPLAZZA_HPP
#define CPP_PLAZZA_PROCESSPLAZZA_HPP

#include <functional>
#include <list>
#include "Thread.hpp"
#include "Process.hpp"
#include "Scrapper.hpp"

#define ONE_SEC        (1000000)

namespace plazza
{
  class ProcessPlazza
  {
   private:
    std::list<Order>      _orders;
    NamedPipe*            _np;
    std::list<IThread *>  _threads;
    IProcess*		          _process;
   public:
    ProcessPlazza(std::list<Order> orders, NamedPipe *np);
    virtual ~ProcessPlazza();

    void	start();
    void 	processLoop();
  };
}


#endif //CPP_PLAZZA_PROCESSPLAZZA_HPP
