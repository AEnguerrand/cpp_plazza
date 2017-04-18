/*
** Process.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/Process.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 11:16:44 2017 Enguerrand Allamel
** Last update Tue Apr 18 11:16:44 2017 Enguerrand Allamel
*/

#include "Process.hpp"

Process::Process()
{
  this->_pid = fork();
}

Process::~Process()
{
  if (this->_pid > 0)
    kill(this->_pid, SIGKILL);
}

bool Process::isChild() const
{
  if (this->_pid == 0)
    return (true);
  return (false);
}