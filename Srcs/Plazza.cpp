/*
** plazza.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:33 2017 Quentin Metge
** Last update Tue Apr 18 18:41:04 2017 Quentin Metge
*/

#include "Plazza.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Plazza::Plazza(const int poolSize) : _poolSize(poolSize){
    this->_ordersType.push_back("EMAIL_ADDRESS");
    this->_ordersType.push_back("IP_ADDRESS");
    this->_ordersType.push_back("PHONE_NUMBER");
    this->mainLoop();
  }

  Order::Order(std::string _fileName, std::string _type){
    this->type = _type;
    this->fileName = _fileName;
    this->file.open(this->fileName);
    if (!this->file.is_open())
      throw Error("Can't open: " + this->fileName + ".");
  }

  Order::Order(Order const& other){
    this->fileName = other.fileName;
    this->type = other.type;
    if (this->file.is_open())
      this->file.close();
    this->file.open(this->fileName);
    if (!this->file.is_open())
      throw Error("Can't open: " + this->fileName + ".");
  }

  Order const& Order::operator=(Order other){
    this->fileName = other.fileName;
    this->type = other.type;
    if (this->file.is_open())
      this->file.close();
    this->file.open(this->fileName);
    if (!this->file.is_open())
      throw Error("Can't open: " + this->fileName + ".");
    return (*this);
  }

  Order::~Order(void){
    this->file.close();
  }

  /*****************/
  /*    Actions    */
  /*****************/
  plazza::TokenType     Plazza::getTypeOfToken(std::string token){
    if (std::find(this->_ordersType.begin(), this->_ordersType.end(), token) != this->_ordersType.end())
      return (TokenType::ORDER);
    return (TokenType::DEFAULT);
  }

  void                  Plazza::mainLoop(void){

    std::string         buffer;
    std::string         token;
    std::string         substr;

    while (getline(std::cin, buffer)){
      std::stringstream lineStream(buffer);
      while(lineStream.good()){
        getline(lineStream, substr, ';');
        std::stringstream lineStream(substr);
        std::vector<std::string>  fileTab;
        std::string               type;
        while (lineStream >> token && this->getTypeOfToken(token) == TokenType::DEFAULT){
          fileTab.push_back(token);
        }
        type = token;
        if (!fileTab.empty() && !type.empty()){
          if (fileTab.empty())
            throw Error("Need file for this order: " + type + ".");
          else if (type.empty())
            throw Error("Need order for this file: " + fileTab[0] + ".");
          if (std::find(this->_ordersType.begin(), this->_ordersType.end(), type) != this->_ordersType.end()){
            for (size_t i = 0; i < fileTab.size(); i++){
              this->_orderList.push_back(Order(fileTab[i], type));
            }
          }
          else
            throw Error("This order doesn't exist: " + type + ".");
        }
      }
    }
  }

  /*****************/
  /*     Getter    */
  /*****************/
  size_t                      Plazza::getPoolSize(void) const{
    return (this->_poolSize);
  }

  std::vector<std::string>    Plazza::getOrdersType(void) const{
    return (this->_ordersType);
  }

  /*****************/
  /*     Setter    */
  /*****************/

}
