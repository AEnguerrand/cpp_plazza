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
  this->pid_ = fork();
}

Process::~Process()
{
  if (this->pid_ > 0)
    kill(this->pid_, SIGKILL);
}

pid_t Process::getPid() const
{
  return this->pid_;
}