/*
** ProcessInfo.hpp for cpp_plazza in /home/enguerrand/delivery/cpp_plazza/ProcessInfo.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sun Apr 30 14:00:17 2017 Enguerrand Allamel
** Last update Sun Apr 30 14:00:17 2017 Enguerrand Allamel
*/

#ifndef CPP_PLAZZA_PROCESSINFO_HPP
#define CPP_PLAZZA_PROCESSINFO_HPP

namespace plazza
{
  struct	ProcessInfo
  {
    size_t 	type;
    size_t 	id;
    size_t 	orderNb;
    bool 	isEmpty;
    bool	isFull;
  };
}

#endif //CPP_PLAZZA_PROCESSINFO_HPP
