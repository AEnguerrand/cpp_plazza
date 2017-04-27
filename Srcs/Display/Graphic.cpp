/*
** Graphic.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:45 2017 Antoine Dury
** Last update Thu Apr 27 17:40:48 2017 Antoine Dury
*/

#include "Graphic.hpp"

Graphic::Graphic(void *data) : _np("scrapper"), _scroll(0), _blink(true), _blinkCount(0)
{
  plazza::ManagerProcess  *mp = static_cast<plazza::ManagerProcess*>(data);

  (void)mp;
  this->_np.create("READ");
  if (!this->_font.loadFromFile("Srcs/Display/Quicksand.otf"))
    std::cerr << "Unable to load font" << std::endl;
  this->_window.create(sf::VideoMode(900, 685), "Plazza");

  // Init text
  this->_resultsSF.setFont(this->_font);
  this->_resultsSF.setCharacterSize(25);
  this->_resultsSF.setFillColor(sf::Color(255, 255, 255));
  this->_inputSF.setFont(this->_font);
  this->_inputSF.setCharacterSize(25);
  this->_inputSF.setFillColor(sf::Color(0, 0, 0));
  this->_inputSF.setPosition(70, 55);

  for (size_t i = 0; i <= 150; i++)
    this->_results.push_back("RESULTAT " + std::to_string(i));
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
  this->_window.clear(sf::Color(211, 47, 47));

  // Text area
  sf::RectangleShape  textArea(sf::Vector2f(765, 35));
  sf::RectangleShape  borderTextArea(sf::Vector2f(769, 39));
  textArea.setFillColor(sf::Color(255, 255, 255));
  borderTextArea.setFillColor(sf::Color(47, 52, 63));
  textArea.setPosition(65, 55);
  borderTextArea.setPosition(63, 53);
  this->_window.draw(borderTextArea);
  this->_window.draw(textArea);

  // User input
  if (this->_blinkCount % 1000 == 0)
    {
      this->_blink = !this->_blink;
      this->_blinkCount = 0;
    }
  if (this->_blink)
    this->_inputSF.setString(this->_input + "_");
  else
    this->_inputSF.setString(this->_input);
  this->_window.draw(this->_inputSF);
  this->_blinkCount++;
}

void   Graphic::drawResults()
{
  char result[BUFFER_SIZE];

  memset(result, 0, BUFFER_SIZE);
  this->_np.readNP(result, BUFFER_SIZE);
  if (strlen(result) > 0)
    {
      // Get result à stocker dans _results
    }

  for (size_t i = 0; i < 17; i++)
    {
      this->_resultsSF.setPosition(65, 130 + (i * 30));
      if (i + this->_scroll < this->_results.size())
        {
          this->_resultsSF.setString("> " + this->_results[i + this->_scroll]);
          this->_window.draw(this->_resultsSF);
        }
    }
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
            {
              if (event.text.unicode == 13)
                {
                  if (!this->_input.empty())
                    {
                      // Envoi des commandes au manager
                      std::cout << this->_input << std::endl;
                      this->_input.clear();
                    }
                }
              else if (event.text.unicode == 8)
                {
                  if (this->_input.size() > 0)
                    this->_input.resize(this->_input.size() - 1);
                }
              else if (this->_input.size() < 54)
                this->_input += static_cast<char>(event.text.unicode);
            }
          }
        else if (event.type == sf::Event::MouseWheelMoved)
          {
            if (this->_scroll + event.mouseWheel.delta != -1 &&
                this->_scroll + event.mouseWheel.delta != static_cast<int>(this->_results.size()) - 16)
                this->_scroll += event.mouseWheel.delta;
          }
    }
}

void Graphic::getResults(std::string results)
{
  (void)results;
}
