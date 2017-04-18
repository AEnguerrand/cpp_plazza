/*
** main.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:25:02 2017 Quentin Metge
** Last update Tue Apr 18 11:19:45 2017 Antoine Dury
*/

#include "plazza.hpp"

int                 main(int ac, char** av)
{
  try {
    if (ac != 2)
      return (EXIT_FAILURE);
    plazza::Plazza    plazza(std::stoi(av[1]));
  }
  catch (std::exception const& e) {
    std::cerr << "Error : " << e.what() << std::endl;
  }
  return (0);
}
