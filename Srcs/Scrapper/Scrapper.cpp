/*
** Scrapper.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:28 2017 Quentin Metge
** Last update Fri Apr 21 11:11:27 2017 Quentin Metge
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
    bool                  test = true;

    std::cerr << "-> Normal: ";
    try{
      std::regex            regex(this->_order->regexp);
      std::sregex_iterator  next(this->_buffer.begin(), this->_buffer.end(), regex);
      std::sregex_iterator  end;

      while (next != end){
        std::smatch match = *next;
        std::cout << match.str() << std::endl;
        test = false;
        next++;
      }
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    if (test == false)
      std::cerr << "OK" << std::endl;
    else
      std::cerr << "KO" << std::endl;
    return (test);
  }

  std::string             Scrapper::decryptXOR(const std::string& str, const std::string& key)
  {
    std::string ret = str;

    for (size_t i = 0; i < ret.size(); i++){
      ret[i] = ret[i] ^ key[i % key.size()];
    }
    return (ret);
  }

  bool                    Scrapper::scpXor(void){
    bool                  test = true;
    std::string           key = "00";
    std::string           buffer = "";

    std::cerr << "-> Xor: ";
    try{
      key[0] = 0;
      key[1] = 0;
      for (int i1 = 0; i1 < 256; i1++){
        for (int i2 = 0; i2 < 256; i2++){
          key[0] = i1;
          key[1] = i2;
          buffer = this->decryptXOR(this->_buffer, key);
          std::regex            regex(this->_order->regexp);
          std::sregex_iterator  next(buffer.begin(), buffer.end(), regex);
          std::sregex_iterator  end;

          while (next != end){
            std::smatch match = *next;
            std::cout << match.str() << std::endl;
            test = false;
            next++;
          }
        }
      }
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    if (test == false){
      std::cerr << "OK" << std::endl;
      std::cerr << "Key = " << key << std:endl;
    }
    else
      std::cerr << "KO" << std::endl;
    return (test);
  }

  bool                    Scrapper::scpCaesar(void){
    bool                  test = true;
    std::cerr << "-> Caesar: ";
    if (test == false)
      std::cerr << "OK" << std::endl;
    else
      std::cerr << "KO" << std::endl;
    return (test);
  }

  /*****************/
  /*     Getter    */
  /*****************/


  /*****************/
  /*     Setter    */
  /*****************/


}
