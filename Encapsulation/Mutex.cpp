/*
** AMutex.cpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 10:55:05 2017 Enguerrand Allamel
** Last update Mon Apr 10 10:55:05 2017 Enguerrand Allamel
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
  pthread_mutex_init(&(this->_mutex), NULL);
}

void Mutex::lock()
{
  if (pthread_mutex_lock(&this->_mutex) != 0)
    throw Error("Mutex: Fail lock.");
}

bool Mutex::trylock()
{
  if (pthread_mutex_trylock(&this->_mutex))
    return (false);
  return (true);
}

void Mutex::unlock()
{
  pthread_mutex_unlock(&this->_mutex);
}