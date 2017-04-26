/*
** Ip.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Wed Apr 26 11:53:48 2017 Quentin Metge
** Last update Wed Apr 26 13:33:51 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  std::string             Scrapper::nb255(size_t& i){
    std::string           test = "";

    for (int j = 0; j < 3 && isdigit(this->_buffer[i]) && i < this->_buffer.size(); j++){
        test += this->_buffer[i];
        ++i;
    }
    if (test != "" && std::stoi(test) <= 255)
      return (test);
    return ("");
  }

  void                    Scrapper::dispIp(void){
    for (size_t i = 0; i < this->_buffer.size();){
      bool                test = true;
      std::string         res = "";

      if ((i == 0 || this->_buffer[i - 1] == ' ' || this->_buffer[i - 1] == '\t' || this->_buffer[i - 1] == '\n') && isdigit(this->_buffer[i]))
        res = res + this->nb255(i);
      else
        test = false;
      for (int j = 0; j < 3; ++j){
        if (res != "" && this->_buffer[i] == '.'){
          ++i;
          res = res + ".";
        }
        else
          test = false;
        if (res != "" && isdigit(this->_buffer[i]))
          res = res + this->nb255(i);
        else
          test = false;
      }
      if (test && (i == 0 || this->_buffer[i] == ' ' || this->_buffer[i] == '\t' || this->_buffer[i] == '\n'))
        std::cout << res << std::endl;
      else
        ++i;
    }
  }

}
