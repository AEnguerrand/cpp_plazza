/*
** Phone.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Wed Apr 26 13:58:10 2017 Quentin Metge
** Last update Thu Apr 27 00:02:20 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  std::string       Scrapper::nbXX(std::string const& buffer, size_t& i){
    std::string           test = "";

    for (int j = 0; j < 2 && buffer[i]; ++j){
      if (!isdigit(buffer[i]))
        return ("");
      test += buffer[i];
      ++i;
    }
    return (test);
  }

  void              Scrapper::dispPhone(std::string const& buffer){
    for (size_t i = 0; i < buffer.size();){
      bool                test = true;
      std::string         res = "";

      if ((i == 0 || buffer[i - 1] == ' ' || buffer[i - 1] == '\t' || buffer[i - 1] == '\n') && isdigit(buffer[i])){
        for (int j = 0; j < 5 && test; ++j){
          std::string tmp = nbXX(buffer, i);
          if (tmp == "")
            test = false;
          res = res + tmp;
          if (test && buffer[i] && j < 4 && buffer[i] == ' '){
            res = res + buffer[i];
            ++i;
          }
        }
        if (test && (i == buffer.size() || buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n'))
          this->dispResult(res);
      }
      else
        ++i;
    }
  }

}