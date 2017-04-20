/*
** Scrapper.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:28 2017 Quentin Metge
** Last update Thu Apr 20 18:05:59 2017 Quentin Metge
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
    bool                test = true;

    std::cerr << "-> Normal" << std::endl;
    try{
      std::regex            regex(this->_order->regexp);
      std::sregex_iterator  next(this->_buffer.begin(), this->_buffer.end(), regex);
      std::sregex_iterator  end;

      while (next != end){
        std::smatch match = *next;
        std::cout << match.str() << std::endl;
        next++;
      }
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    return (test);
  }

  bool                    Scrapper::scpXor(void){
    std::cerr << "-> Xor" << std::endl;
    return (true);
  }

  bool                    Scrapper::scpCaesar(void){
    std::cerr << "-> Caesar" << std::endl;
    return (true);
  }

  /*****************/
  /*     Getter    */
  /*****************/


  /*****************/
  /*     Setter    */
  /*****************/


}
