/*
** Text.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Graphic
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 11:59:07 2017 Antoine Dury
** Last update Thu Apr 27 17:09:57 2017 Quentin Metge
*/

#include "Order.hpp"
#include "NamedPipe.hpp"

void          *createDisplay(void *data)
{
  NamedPipe   np("scrapper");
  char        result[BUFFER_SIZE];
  std::string res;

  data = static_cast<void *>(data);
  np.create("READ");
  while (true)
  {
    memset(result, 0, BUFFER_SIZE);
    np.readNP(result, BUFFER_SIZE);
    if (strlen(result) > 0)
      std::cout << result;
  }
  return (NULL);
}
