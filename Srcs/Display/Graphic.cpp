/*
** Graphic.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:45 2017 Antoine Dury
** Last update Wed Apr 26 22:50:42 2017 Antoine Dury
*/

#include "Graphic.hpp"

Graphic::Graphic(void *data) : _np("scrapper")
{
  plazza::ManagerProcess  *mp = static_cast<plazza::ManagerProcess*>(data);

  (void)mp;
  this->_np.create("READ");
  if (!this->_font.loadFromFile("Srcs/Display/Quicksand.otf"))
    std::cerr << "Unable to load font" << std::endl;
  this->_window.create(sf::VideoMode(1200, 700), "Plazza");
  this->_resultsSF.setFont(this->_font);
  this->_inputSF.setFont(this->_font);
}

Graphic::~Graphic()
{
  this->_window.close();
}

void      *createDisplay(void *data)
{
  Graphic graphic(data);

  graphic.display();
  return (NULL);
}

void        Graphic::display()
{
  while (this->_window.isOpen())
    {
      this->getEvent();
      this->drawInterface();
      this->drawResults();
      this->_window.display();
    }
}

void                  Graphic::drawInterface()
{
  // Background
  this->_window.clear(sf::Color(121, 85, 72));

  // Text area
  sf::RectangleShape  textArea(sf::Vector2f(500, 35));
  textArea.setFillColor(sf::Color(255, 255, 255));
  textArea.setPosition(20, 50);
  this->_window.draw(textArea);

  // User input
  this->_inputSF.setFillColor(sf::Color(0, 0, 0));
  this->_inputSF.setPosition(25, 48);
  this->_inputSF.setString(this->_input + "_");
  this->_window.draw(this->_inputSF);
}

void   Graphic::drawResults()
{
  char result[BUFFER_SIZE];

  memset(result, 0, BUFFER_SIZE);
  this->_np.readNP(result, BUFFER_SIZE);
  if (strlen(result) > 0)
    this->_resultsSF.setString(result);
  this->_window.draw(this->_resultsSF);
}

void          Graphic::getEvent()
{
  sf::Event   event;

  while (this->_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            this->_window.close();
        else if (event.type == sf::Event::TextEntered)
          {
            if (event.text.unicode < 128)
              this->_input += static_cast<char>(event.text.unicode);
          }
    }
}
