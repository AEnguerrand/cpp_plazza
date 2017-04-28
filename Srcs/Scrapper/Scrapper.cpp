/*
** Scrapper.cpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:28 2017 Quentin Metge
** Last update Fri Apr 28 16:03:38 2017 Quentin Metge
*/

#include "Scrapper.hpp"

namespace plazza
{

  /*****************/
  /*    Coplien    */
  /*****************/
  Scrapper::Scrapper(Order *order) : _order(order), _np("scrapper"){
    bool        cyphered = true;

    this->_np.create("WRITE");
    if (this->initBuffer()){
      this->_typeFct["PHONE_NUMBER"] = [&](std::string const& buffer){this->dispPhone(buffer);};
      this->_typeFct["EMAIL_ADDRESS"] = [&](std::string const& buffer){this->dispEmail(buffer);};
      this->_typeFct["IP_ADDRESS"] = [&](std::string const& buffer){this->dispIp(buffer);};
      //this->_scrapperFct.push_back(std::bind(&Scrapper::scpNormal, this));
      this->_scrapperFct.push_back(std::bind(&Scrapper::scpCaesar, this));
      this->_scrapperFct.push_back(std::bind(&Scrapper::scpXor, this));
      for (size_t i = 0; cyphered && i < this->_scrapperFct.size(); i++){
        cyphered = this->_scrapperFct[i]();
      }
    }
    this->_np.destroy();
  }

  /*****************/
  /*    Actions    */
  /*****************/
  void                    Scrapper::dispResult(std::string const& str){
    char                  result[str.size()];

    str.copy(result, str.size());
    this->_np.writeNP(result, str.size() * sizeof(char));
  }

  void                    Scrapper::dispMatch(std::string const& buffer){
    std::string           type = std::string(this->_order->type);

    this->_typeFct[type](buffer);
    /*else{
      std::regex            regex(this->_order->regexp);
      std::sregex_iterator  next(this->_buffer.begin(), this->_buffer.end(), regex);
      std::sregex_iterator  end;

      while (next != end){
        std::smatch match = *next;
        std::cout << match.str() << std::endl;
        next++;
      }
    }*/
  }

  bool                    Scrapper::initBuffer(void){
    std::ifstream         ss;

    ss.open(this->_order->fileName);
    if (!ss.is_open()){
      //std::cerr << "Unable to open file " << this->_order.fileName << "." << std::endl;
      return false;
    }
    std::string           line;
    while (getline(ss, line)){
      this->_buffer += line + " ";
    }
    ss.close();
    return true;
  }

  bool                    Scrapper::scpNormal(void){
    try{
      this->dispMatch(this->_buffer);
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    return (true);
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
    std::string           key = "00";
    std::string           buffer = "";

    try{
      key[0] = 0;
      key[1] = 0;
      for (int i1 = 0; i1 < 256; i1++){
        for (int i2 = 0; i2 < 256; i2++){
          key[0] = i1;
          key[1] = i2;
          buffer = this->decryptXOR(this->_buffer, key);
          this->dispMatch(buffer);
        }
      }
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    return (true);
  }

  std::string             Scrapper::decryptCaesar(const std::string& str, const std::string& key)
  {
    std::string   ret = str;

    for (size_t i = 0; i < ret.size(); i++){
      ret[i] -= key[0];
    }
    return (ret);
  }

  bool                    Scrapper::scpCaesar(void){
    std::string           key = "0";
    std::string           buffer = "";

    try{
      for (int i = 1; i <= 2; i++){
        key[0] = i;
        buffer = this->decryptCaesar(this->_buffer, key);
        this->dispMatch(buffer);
      }
    }
    catch(std::exception const& e){
      std::cerr << "Error : Regexp." << std::endl;
      return (true);
    }
    return (true);
  }

  /*****************/
  /*     Getter    */
  /*****************/

  /*****************/
  /*     Setter    */
  /*****************/

}
