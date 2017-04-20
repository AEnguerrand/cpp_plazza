/*
** Scrapper.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:28 2017 Quentin Metge
** Last update Thu Apr 20 15:42:54 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Scrapper::Scrapper(Order const& order) : _order(order){
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
    if (!this->_order.file.ss.is_open()){
      std::cerr << "Unable to open file " << this->_order.file.name << "." << std::endl;
      return ;
    }
    std::string line;
    while (getline(this->_order.file.ss, line)){
      this->_buffer += line;
    }
    this->_order.file.ss.close();
  }

  bool          Scrapper::scpNormal(void){
    return (true);
  }

  bool          Scrapper::scpXor(void){
    return (true);
  }
  bool          Scrapper::scpCaesar(void){
    return (true);
  }

  /*****************/
  /*     Getter    */
  /*****************/


  /*****************/
  /*     Setter    */
  /*****************/


}
