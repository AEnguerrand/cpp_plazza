/*
** main.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:25:02 2017 Quentin Metge
** Last update Mon Apr 17 19:40:43 2017 Quentin Metge
*/

#include "plazza.hpp"

int                 main(int ac, char** av)
{
  if (ac != 2)
    return (EXIT_FAILURE);
  plazza::Plazza    plazza(std::stoi(av[1]));
  return (0);
}
