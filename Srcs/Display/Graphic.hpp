/*
** Graphic.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:53 2017 Antoine Dury
** Last update Wed Apr 26 16:10:47 2017 Antoine Dury
*/

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

class Graphic
{
  public:
    Graphic(void);
    virtual ~Graphic(void);
};

void *createDisplay(void *data);

#endif
