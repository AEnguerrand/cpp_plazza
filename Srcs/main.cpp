/*
** main.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:25:02 2017 Quentin Metge
** Last update Wed Apr 19 11:00:26 2017 Quentin Metge
*/

#include "Plazza.hpp"

int main(int ac, char **av)
{
  try
    {
      if (ac != 2)
	{
	  std::cerr << "Usage : " + std::string(av[0]) + " <Number of threads per process>" << std::endl;
	  return (EXIT_FAILURE);
	}
      if (std::stoi(av[1]) <= 0)
	{
	  std::cerr << "Number of threads per process is only > 0." << std::endl;
	  return (EXIT_FAILURE);
	}
      plazza::Plazza plazza(std::stoi(av[1]));
    }
  catch (std::exception const &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  return (0);
}
