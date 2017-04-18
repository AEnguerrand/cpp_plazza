/*
** CondVar.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/CondVar.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 12:55:34 2017 Enguerrand Allamel
** Last update Tue Apr 18 12:55:34 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_CONDVAR_HPP
#define CPP_PLAZZA_CONDVAR_HPP

#include "ICondVar.hpp"

class CondVar : public ICondVar
{
 private:
  pthread_cond_t	_cond;
  pthread_mutex_t	_mutex;
 public:
  CondVar();
  virtual ~CondVar();

  virtual void wait();
  virtual void wake();
};


#endif //CPP_PLAZZA_CONDVAR_HPP
