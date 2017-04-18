/*
** AMutex.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 10:55:05 2017 Enguerrand Allamel
** Last update Mon Apr 10 10:55:05 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_MUTEX_HPP
#define CPP_PLAZZA_MUTEX_HPP

#include "IMutex.hpp"

class Mutex : public IMutex
{
 private:
  pthread_mutex_t mutex;

 public:
  Mutex();
  virtual ~Mutex(void) {}

  virtual void lock(void);
  virtual void unlock(void);
  virtual bool trylock(void);
};


#endif //CPP_PLAZZA_AMUTEX_HPP
