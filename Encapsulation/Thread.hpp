/*
** AThread.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Apr 10 11:36:07 2017 Enguerrand Allamel
** Last update Mon Apr 10 11:36:07 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_THREAD_HPP
#define CPP_PLAZZA_THREAD_HPP

#include "IThread.hpp"

class Thread : public IThread
{
 private:
  pthread_t		_thread;
  IThread::STATUS 	_status;
  void			*(*_ptr_func)(void *);
  void 			*_data;

 public:
  Thread(void *(*ptr_func)(void *), void *data);
  virtual ~Thread() {}

  virtual IThread::STATUS getStatus() const;
  virtual void start();
  virtual void wait();
};


#endif //CPP_PLAZZA_ATHREAD_HPP
