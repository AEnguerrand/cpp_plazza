/*
** Scrapper.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:28 2017 Quentin Metge
** Last update Thu Apr 20 16:53:23 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Scrapper::Scrapper(Order* order) : _order(order){
    bool        cyphered = true;

    this->_scrapperFct.push_back(std::bind(&Scrapper::scpNormal, this));
    this->_scrapperFct.push_back(std::bind(&Scrapper::scpXor, this));
    this->_scrapperFct.push_back(std::bind(&Scrapper::scpCaesar, this));
    this->initBuffer();
    for (size_t i = 0; cyphered && i < this->_scrapperFct.size(); i++){
      cyphered = this->_scrapperFct[i]();
    }
  }

  Scrapper::~Scrapper(void){

  }

  /*****************/
  /*    Actions    */
  /*****************/
  void          Scrapper::initBuffer(void){
    if (!this->_order->file.ss.is_open()){
      std::cerr << "Unable to open file " << this->_order->file.name << "." << std::endl;
      return ;
    }
    std::string line;
    while (getline(this->_order->file.ss, line)){
      this->_buffer += line + " ";
    }
    this->_order->file.ss.close();
  }

  bool                    Scrapper::scpNormal(void){
    std::regex            e(this->_order->regexp);
    std::string           s(this->_buffer);
    std::smatch           m;

    while (std::regex_search(s, m, e)){
      for (auto x:m){
        std::cerr << x << std::endl;
      }
      s = m.suffix().str();
    }
    return (false);
  }

  bool                    Scrapper::scpXor(void){
    return (true);
  }

  bool                    Scrapper::scpCaesar(void){
    return (true);
  }

  /*****************/
  /*     Getter    */
  /*****************/


  /*****************/
  /*     Setter    */
  /*****************/


}
