/*
** Graphic.cpp for cpp_plazza in /home/antoine/rendu/cpp/cpp_plazza/Srcs/Display
**
** Made by Antoine Dury
** Login   <antoine.dury@epitech.eu>
**
** Started on  Tue Apr 25 14:05:45 2017 Antoine Dury
** Last update Fri Apr 28 13:44:10 2017 Antoine Dury
*/

#include "Graphic.hpp"

Graphic::Graphic(void *data) : _np("scrapper"), _scroll(0), _blink(true), _blinkCount(0)
{
  this->_plazza = static_cast<plazza::Plazza*>(data);
  this->_np.create("READ");
  if (!this->_font.loadFromFile("Srcs/Display/Quicksand.otf"))
    std::cerr << "Unable to load font" << std::endl;
  this->_window.create(sf::VideoMode(900, 685), "Plazza");

  // Init text
  this->_inputSF.setFont(this->_font);
  this->_resultsSF.setFont(this->_font);
  this->_statusTasks.setFont(this->_font);
  this->_statusProcess.setFont(this->_font);
  this->_statusThreads.setFont(this->_font);
  this->_statusOrders.setFont(this->_font);
  this->_resultsSF.setCharacterSize(25);
  this->_inputSF.setCharacterSize(25);
  this->_statusTasks.setCharacterSize(25);
  this->_statusProcess.setCharacterSize(25);
  this->_statusThreads.setCharacterSize(25);
  this->_statusOrders.setCharacterSize(25);
  this->_resultsSF.setFillColor(sf::Color::White);
  this->_inputSF.setFillColor(sf::Color::Black);
  this->_statusTasks.setFillColor(sf::Color::White);
  this->_statusProcess.setFillColor(sf::Color::White);
  this->_statusThreads.setFillColor(sf::Color::White);
  this->_statusOrders.setFillColor(sf::Color::White);
  this->_inputSF.setPosition(70, 55);
  this->_statusTasks.setPosition(620, 130);
  this->_statusProcess.setPosition(585, 160);
  this->_statusThreads.setPosition(586, 190);
  this->_statusOrders.setPosition(601, 220);
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

  // Stats
  this->_statusTasks.setString("Current tasks : " + std::to_string(this->_plazza->getManagerProcess()._status.tasks));
  this->_statusProcess.setString("Current process : " + std::to_string(this->_plazza->getManagerProcess()._status.process));
  this->_statusThreads.setString("Current threads : " + std::to_string(this->_plazza->getManagerProcess()._status.threads));
  this->_statusOrders.setString("Current orders : " + std::to_string(this->_plazza->getManagerProcess()._status.orders));
  this->_window.draw(this->_statusTasks);
  this->_window.draw(this->_statusProcess);
  this->_window.draw(this->_statusThreads);
  this->_window.draw(this->_statusOrders);
}

void          Graphic::drawResults()
{
  char        tmp[BUFFER_SIZE];
  std::string results;

  memset(tmp, 0, BUFFER_SIZE);
  this->_np.readNP(tmp, BUFFER_SIZE);
  if (strlen(tmp) > 0)
    {
      results = tmp;
      getResults(results);
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
            if (event.text.unicode == 13)
              {
                if (!this->_input.empty())
                  {
                    this->_plazza->getNextLine(this->_input);
                    this->_plazza->getManagerProcess().addOrder(this->_plazza->getOrderList());
                    this->_plazza->clearOrderList();
                    this->_input.clear();
                  }
              }
            else if (event.text.unicode == 8)
              {
                if (this->_input.size() > 0)
                  this->_input.resize(this->_input.size() - 1);
              }
            else if (event.text.unicode < 128 && this->_input.size() < 54)
              this->_input += static_cast<char>(event.text.unicode);
          }
        else if (event.type == sf::Event::MouseWheelMoved)
          {
            if (this->_scroll + event.mouseWheel.delta != -1 &&
                this->_scroll + event.mouseWheel.delta != static_cast<int>(this->_results.size()) - 16)
                this->_scroll += event.mouseWheel.delta;
          }
    }
}

void                Graphic::getResults(std::string const& results)
{
  std::stringstream ss(results);
  std::string       token;

  if (ss.good())
  {
    while (std::getline(ss, token, '\n')){
      if (!token.empty())
        this->_results.push_back(token);
    }
  }
}
