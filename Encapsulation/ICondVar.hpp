/*
** ICondVar.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ICondVar.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 12:55:18 2017 Enguerrand Allamel
** Last update Tue Apr 18 12:55:18 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_ICONDVAR_HPP
#define CPP_PLAZZA_ICONDVAR_HPP

#include <iostream>
#include <pthread.h>

class ICondVar
{
 public:
  virtual ~ICondVar() {};

  virtual void wait() = 0;
  virtual void wake() = 0;
};

#endif //CPP_PLAZZA_ICONDVAR_HPP
