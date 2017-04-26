/*
** Graphic.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:53 2017 Antoine Dury
** Last update Wed Apr 26 16:31:25 2017 Antoine Dury
*/

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ManagerProcess.hpp"
#include "NamedPipe.hpp"

class Graphic
{
  public:
    Graphic(void) {}
    Graphic(void*);
    virtual ~Graphic(void);

    void                      display(void);

  private:
    sf::RenderWindow          _window;
    sf::Font                  _font;
    std::vector<std::string>  _results;
};

void *createDisplay(void *data);

#endif
