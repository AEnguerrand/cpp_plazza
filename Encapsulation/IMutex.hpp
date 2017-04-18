/*
** IMutex.hpp for plazza_bs in /home/enguerrand/delivery/plazza_bs/IMutex.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 10:54:34 2017 Enguerrand Allamel
** Last update Mon Apr 10 10:54:34 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_IMUTEX_HPP
#define CPP_PLAZZA_IMUTEX_HPP

#include <iostream>
#include <pthread.h>

class IMutex {
 public:
  virtual ~IMutex(void) {}

  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
};


#endif //CPP_PLAZZA_IMUTEX_HPP
