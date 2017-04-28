/*
** Ip.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Wed Apr 26 11:53:48 2017 Quentin Metge
** Last update Fri Apr 28 15:45:09 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  std::string           Scrapper::beforePoint(std::string const& buffer, int i){
    std::string         word = "";
    std::string         res = "";

    if (i - 1 >= 0 && this->_numerical.find_first_of(buffer[--i]) != std::string::npos){
      for (int j = 0; i >= 0 && j < 3 && this->_numerical.find_first_of(buffer[i]) != std::string::npos; j++){
        word += buffer[i--];
      }
    }
    else
      return ("");
    res = std::string(word.rbegin(), word.rend());
    return (std::stoi(res) <= 255 ? res : "");
  }

  std::string           Scrapper::afterPoint(std::string const& buffer, size_t i){
    std::string         word = "";
    std::string         res = "";
    std::string         tmp = "";

    if (buffer[i + 1] && this->_numerical.find_first_of(buffer[++i]) != std::string::npos){
      for (int j = 0; buffer[i] && j < 3 && this->_numerical.find_first_of(buffer[i]) != std::string::npos; j++){
        tmp += buffer[i++];
      }
      if (std::stoi(tmp) <= 255 && buffer[i] && buffer[i] == '.')
        word += tmp + buffer[i++];
      else
        return ("");
      tmp.clear();
      for (int j = 0; buffer[i] && j < 3 && this->_numerical.find_first_of(buffer[i]) != std::string::npos; j++){
        tmp += buffer[i++];
      }
      if (std::stoi(tmp) <= 255 && buffer[i] && buffer[i] == '.')
        word += tmp + buffer[i++];
      else
        return ("");
      tmp.clear();
      for (int j = 0; buffer[i] && j < 3 && this->_numerical.find_first_of(buffer[i]) != std::string::npos; j++){
        tmp += buffer[i++];
      }
      if (std::stoi(tmp) <= 255)
        word += tmp;
      else
        return ("");
    }
    else
      return ("");
    return (word);
  }

  void                  Scrapper::dispIp(std::string const& buffer){
    std::string         wordBefore = "";
    std::string         wordAfter = "";
    size_t              found = buffer.find_first_of('.');

    while (found != std::string::npos){
      if (!(wordBefore = beforePoint(buffer, found)).empty()){
          if (!(wordAfter = afterPoint(buffer, found)).empty()){
            this->dispResult(wordBefore + '.' + wordAfter);
          }
      }
      found = buffer.find_first_of('.', found + 1);
    }
  }


}
