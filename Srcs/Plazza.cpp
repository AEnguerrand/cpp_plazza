/*
** plazza.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:33 2017 Quentin Metge
** Last update Thu Apr 20 17:15:45 2017 Antoine Dury
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
    this->file = File(_fileName);
    this->type = _type;
    if (this->type == "PHONE_NUMBER")
      this->regexp = "([0-9][0-9] ?){5}";
    else if (this->type == "EMAIL_ADDRESS")
      this->regexp = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+";
    else if (this->type == "IP_ADDRESS")
      this->regexp = "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?).(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)";
    else
      throw Error("This order is not known.");
  }

  File::File(std::string _fileName){
    this->name = _fileName;
    this->ss.open(this->name);
    if (!this->ss.is_open())
      throw Error("Can't open: " + this->name + ".");
  }

  File::File(File const& other){
    this->name = other.name;
    if (this->ss.is_open())
      this->ss.close();
    this->ss.open(this->name);
    if (!this->ss.is_open())
      throw Error("Can't open: " + this->name + ".");
  }

  File const&         File::operator=(File other){
    this->name = other.name;
    if (this->ss.is_open())
      this->ss.close();
    this->ss.open(this->name);
    if (!this->ss.is_open())
      throw Error("Can't open: " + this->name + ".");
    return (*this);
  }

  File::~File(void){
    if (!this->ss.is_open())
      this->ss.close();
  }

  /*****************/
  /*    Actions    */
  /*****************/
  void                  Order::display(void){
    std::cerr << "Order:\t" << this->file.name << "\t->\t" << this->type << std::endl;
  }

  plazza::TokenType     Plazza::getTypeOfToken(std::string token){
    if (std::find(this->_ordersType.begin(), this->_ordersType.end(), token) != this->_ordersType.end())
      return (TokenType::ORDER);
    return (TokenType::DEFAULT);
  }

  void                  Plazza::getNextLine(std::string buffer){
    std::string         token;
    std::string         substr;

    std::stringstream lineStream(buffer);
    while(lineStream.good()){
      getline(lineStream, substr, ';');
      std::stringstream lineStream(substr);
      std::vector<std::string>  fileTab;
      std::string       type;
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

  void                  Plazza::mainLoop(void){
    std::string         buffer;
    ManagerProcess	managerProcess(this->getPoolSize());

    while (getline(std::cin, buffer)){
    	this->getNextLine(buffer);
    	this->displayOrderList();
    	managerProcess.addOrder(this->_orderList);
    }
  }

  void                  Plazza::displayOrderList(void){
    for (auto it = this->_orderList.begin(); it != this->_orderList.end(); it++){
      (*it).display();
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
