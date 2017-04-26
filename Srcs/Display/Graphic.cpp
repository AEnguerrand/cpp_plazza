/*
** Graphic.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:45 2017 Antoine Dury
** Last update Wed Apr 26 16:31:18 2017 Antoine Dury
*/

#include "Graphic.hpp"

Graphic::Graphic(void *data)
{
  plazza::ManagerProcess  *mp = static_cast<plazza::ManagerProcess*>(data);

  (void)mp;
  if (!this->_font.loadFromFile("Srcs/Display/Quicksand.otf"))
    std::cerr << "Unable to load font" << std::endl;
  this->_window.create(sf::VideoMode(800, 600), "My window");
}

Graphic::~Graphic()
{
  this->_window.close();
}

void        Graphic::display()
{
  sf::Text  text;
  NamedPipe np("scrapper");
  char      result[4096];

  text.setFont(this->_font);
  text.setString("Test");
  np.create("READ");
  while (this->_window.isOpen())
    {
      sf::Event   event;

      memset(result, 0, 4096);
      np.readNP(result, 4096);
      if (strlen(result) > 0)
        std::cout << "GRAPHIC => " << result << std::endl;
      while (this->_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->_window.close();
        }
      this->_window.clear();
      this->_window.draw(text);
      this->_window.display();
    }
}

void      *createDisplay(void *data)
{
  Graphic graphic(data);

  graphic.display();
  return (NULL);
}
