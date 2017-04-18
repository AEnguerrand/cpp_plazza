/*
** Error.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 18 11:17:11 2017 Antoine Dury
** Last update Tue Apr 18 11:17:38 2017 Antoine Dury
*/

#ifndef ERROR_HPP
# define ERROR_HPP

#include <exception>

class Error: public std::exception
{
  public:
    Error(const std::string& msg = "") throw() : _msg(msg) {}
    virtual ~Error() throw() {}

    virtual const char* what() const throw()
    {
      return (_msg.c_str());
    }

  private:
    std::string _msg;
};

#endif
