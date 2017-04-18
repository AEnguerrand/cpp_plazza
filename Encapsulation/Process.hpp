/*
** Process.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/Process.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 11:16:44 2017 Enguerrand Allamel
** Last update Tue Apr 18 11:16:44 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_PROCESS_HPP
#define CPP_PLAZZA_PROCESS_HPP

#include "IProcess.hpp"

class Process : public IProcess
{
 private:
  pid_t         	_pid;
  IProcess::STATUS 	_status;

 public:
  Process();
  virtual ~Process();

  virtual void start();
  virtual void wait();
  virtual bool isChild() const;
};


#endif //CPP_PLAZZA_PROCESS_HPP
