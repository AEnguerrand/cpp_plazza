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
  pthread_mutex_init(&(this->_mutex), NULL);
  pthread_cond_init(&(this->_cond), NULL);
}

CondVar::~CondVar()
{

}

void CondVar::wait()
{
  pthread_cond_wait(&(this->_cond), &(this->_mutex));
}

void CondVar::wake()
{
  pthread_cond_broadcast(&(this->_cond));
}