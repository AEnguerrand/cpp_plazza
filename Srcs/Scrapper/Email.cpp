/*
** Email.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Fri Apr 28 10:15:04 2017 Quentin Metge
** Last update Fri Apr 28 12:07:34 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{
  std::string       printable = "0123456789abcdefghijklmnopqrstuvwxyz_-.";

  std::string       Scrapper::isWord(std::string const& buffer, size_t& i){
    std::string     res = "";

    if (printable.find_first_of(buffer[i]) != std::string::npos){
      res = res + buffer[i++];
      while (printable.find_first_of(buffer[i]) != std::string::npos){
        res = res + buffer[i++];
      }
    }
    else
      return ("");
    return (res);
  }

  void              Scrapper::dispEmail(std::string const& buffer){
    for (size_t i = 0; i < buffer.size();){
      bool                test = true;
      std::string         res = "";
      std::string         word;

      if ((i == 0 || buffer[i - 1] == ' ' || buffer[i - 1] == '\t' || buffer[i - 1] == '\n') && printable.find_first_of(buffer[i]) != std::string::npos){
        word = this->isWord(buffer, i);
        if (!word.empty()){
          res = res + word;
          if (buffer[i] == '@'){
            res = res + buffer[i++];
            word = this->isWord(buffer, i);
            if (!word.empty()){
              res = res + word;
              if (res.find_first_of('.') == std::string::npos)
                test = false;
            }
            else
              test = false;
          }
          else
            test = false;
        }
        else
          test = false;
        ++i;
        //if (test && (i == buffer.size() || buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n'))
        if (test)
          this->dispResult(res);
      }
      else
        ++i;
    }
  }

}
