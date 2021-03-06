/*
** Graphic.hpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:53 2017 Antoine Dury
** Last update Thu Apr 27 19:44:50 2017 Antoine Dury
*/

#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Plazza.hpp"
#include "NamedPipe.hpp"

class Graphic
{
  public:
    Graphic(void) {}
    Graphic(void*);
    virtual ~Graphic(void);

    void                      display(void);
    void                      drawInterface(void);
    void                      drawResults(void);
    void                      getEvent(void);
    void                      getResults(std::string const& results);

  private:
    sf::Font                  _font;
    sf::Text                  _resultsSF;
    sf::Text                  _inputSF;
    sf::Text                  _statusTasks;
    sf::Text                  _statusProcess;
    sf::Text                  _statusThreads;
    sf::Text                  _statusOrders;
    sf::RenderWindow          _window;

    plazza::Plazza            *_plazza;
    NamedPipe                 _np;
    int                       _scroll;
    bool                      _blink;
    size_t                    _blinkCount;
    std::string               _input;
    std::vector<std::string>  _results;
};

void *createDisplay(void *data);

#endif
