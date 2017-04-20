/*
** CondVar.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/CondVar.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Apr 18 12:55:34 2017 Enguerrand Allamel
** Last update Tue Apr 18 12:55:34 2017 Enguerrand Allamel
*/

#include "CondVar.hpp"

CondVar::CondVar()
{
  if ((pthread_mutex_init(&(this->_mutex), NULL) != 0) &&
	  (pthread_cond_init(&(this->_cond), NULL) != 0))
    throw Error("CondVar: Fail init.");
}

CondVar::~CondVar()
{

}

void CondVar::wait()
{
  if (pthread_cond_wait(&(this->_cond), &(this->_mutex)) != 0)
    throw Error("CondVar: Fail wait.");
}

void CondVar::wake()
{
  if (pthread_cond_broadcast(&(this->_cond)) != 0)
    throw Error("CondVar: Fail broadcast.");
}