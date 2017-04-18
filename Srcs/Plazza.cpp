/*
** plazza.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Mon Apr 17 19:27:33 2017 Quentin Metge
** Last update Tue Apr 18 12:57:49 2017 Quentin Metge
*/

#include "Plazza.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Plazza::Plazza(const int poolSize) : _poolSize(poolSize){

  }

  Order::Order(std::string _fileName, OrderType _type){
    this->type = _type;
    this->file.open(_fileName);
    if (!this->file.is_open())
      throw Error("Can't open: " + _fileName);
  }

  Order::~Order(void){
    this->file.close();
  }

  /*****************/
  /*    Actions    */
  /*****************/


  /*****************/
  /*     Getter    */
  /*****************/
  size_t          Plazza::getPoolSize(void) const{
    return (this->_poolSize);
  }

  /*****************/
  /*     Setter    */
  /*****************/

}
