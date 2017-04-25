/*
** Graphic.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:45 2017 Antoine Dury
** Last update Tue Apr 25 14:08:11 2017 Antoine Dury
*/

#include "Graphic.hpp"

Graphic::Graphic() {}

Graphic::~Graphic() {}

void *createDisplay(void *data)
{
  (void)data;
  std::cerr << "createDisplay GRAPHIC called" << std::endl;
  return (NULL);
}
