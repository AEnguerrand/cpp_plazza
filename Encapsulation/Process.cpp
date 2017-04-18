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
  this->_status = IProcess::STATUS::NOT_START;
  this->_pid = -1;
}

void Process::start()
{
  this->_pid = fork();
  this->_status = IProcess::STATUS::RUN;
}

void Process::wait()
{
  int status;

  if (!this->isChild())
    waitpid(this->_pid, &status, 0);
}

Process::~Process()
{
  this->_status = IProcess::STATUS::DEAD;
  if (!this->isChild())
    kill(this->_pid, SIGKILL);
}

bool Process::isChild() const
{
  if (this->_pid == 0)
    return (true);
  return (false);
}