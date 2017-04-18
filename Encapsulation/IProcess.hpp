/*
** IProcess.hpp for CPP_PLAZZA in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 10:17:30 2017 Enguerrand Allamel
** Last update Tue Apr 18 10:17:30 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_IPROCESS_HPP
#define CPP_PLAZZA_IPROCESS_HPP

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

class IProcess
{
 public:
  virtual ~IProcess() {};

  virtual bool isChild() const = 0;
};

#endif //CPP_PLAZZA_IPROCESS_HPP
