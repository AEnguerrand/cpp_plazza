/*
** Ip.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Wed Apr 26 11:53:48 2017 Quentin Metge
** Last update Wed Apr 26 14:51:41 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  std::string             Scrapper::nb255(std::string const& buffer, size_t& i){
    std::string           test = "";

    for (int j = 0; j < 3 && isdigit(buffer[i]) && i < buffer.size(); j++){
        test = test + buffer[i];
        ++i;
    }
    if (test != "" && std::stoi(test) <= 255)
      return (test);
    return ("");
  }

  void                    Scrapper::dispIp(std::string const& buffer){
    for (size_t i = 0; i < buffer.size();){
      bool                test = true;
      std::string         res = "";

      if ((i == 0 || buffer[i - 1] == ' ' || buffer[i - 1] == '\t' || buffer[i - 1] == '\n') && isdigit(buffer[i]))
        res = res + this->nb255(buffer, i);
      else
        test = false;
      for (int j = 0; j < 3; ++j){
        if (res != "" && buffer[i] == '.'){
          ++i;
          res = res + ".";
        }
        else
          test = false;
        if (res != "" && isdigit(buffer[i]))
          res = res + this->nb255(buffer, i);
        else
          test = false;
      }
      if (test && (i == buffer.size() || buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n'))
        std::cout << res << std::endl;
      else
        ++i;
    }
  }

}
