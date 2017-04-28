/*
** plazza.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 22:27:33 2017 Quentin Metge
** Last update Fri Apr 28 20:27:27 2017 Quentin Metge
*/

#include "Plazza.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Plazza::Plazza(const size_t poolSize) : _poolSize(poolSize), _managerProcess(poolSize){
    this->_ordersType.push_back("EMAIL_ADDRESS");
    this->_ordersType.push_back("IP_ADDRESS");
    this->_ordersType.push_back("PHONE_NUMBER");
    this->mainLoop();
  }

  Plazza::~Plazza(){
    unlink("/tmp/*.fifo");
  }

  /*****************/
  /*    Actions    */
  /*****************/
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
            Order       order;

            memset(&order, 0, sizeof(struct Order));
            strcpy(order.fileName, fileTab[i].c_str());
            strcpy(order.type, type.c_str());
            if (std::string(order.type) == "PHONE_NUMBER")
              strcpy(order.regexp, "([0-9][0-9] ?){5}");
            else if (std::string(order.type) == "EMAIL_ADDRESS")
              strcpy(order.regexp, "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
            else if (std::string(order.type) == "IP_ADDRESS")
              strcpy(order.regexp, "(?:(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)\\.){3}(?:0|1[\\d]{0,2}|2(?:[0-4]\\d?|5[0-5]?|[6-9])?|[3-9]\\d?)");
            else
              throw Error("This order is not known.");
            this->_orderList.push_back(order);
          }
        }
        else
          std::cerr << "Error : This order doesn't exist: " << type << "." << std::endl;
      }
    }
  }

  void                  Plazza::mainLoop(void){
    std::string         buffer = " ";
    IThread             *thread = new Thread(&createDisplay, this);

    thread->start();
    while (getline(std::cin, buffer) && buffer != "exit"){
	this->getNextLine(buffer);
	if (!this->_orderList.empty())
	  this->_managerProcess.addOrder(this->_orderList);
      	this->clearOrderList();
    }
    while (!this->_managerProcess.isFinish());
    usleep(1);
    delete thread;
  }

  void                  Plazza::displayOrderList(void){
    for (auto it = this->_orderList.begin(); it != this->_orderList.end(); it++){
       std::cerr << "Order:\t" << (*it).fileName << "\t->\t" << (*it).type << std::endl;
    }
  }

  void                  Plazza::clearOrderList(void)
  {
    this->_orderList.clear();
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

  ManagerProcess              Plazza::getManagerProcess(void) const{
    return (this->_managerProcess);
  }

  std::list<Order>            Plazza::getOrderList(void) const{
    return (this->_orderList);
  }

  /*****************/
  /*     Setter    */
  /*****************/

}
