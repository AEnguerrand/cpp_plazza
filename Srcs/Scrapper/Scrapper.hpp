/*
** Scrapper.hpp for cpp_plazza in /Users/metge_q/rendu/cpp_plazza/Srcs/Scrapper
**
** Made by Quentin Metge
** Login   <metge_q@epitech.net>
**
** Started on  Thu Apr 20 14:31:29 2017 Quentin Metge
** Last update Fri Apr 28 14:43:34 2017 Quentin Metge
*/

#ifndef SCRAPPER_HPP
# define SCRAPPER_HPP

#include <regex>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include "Order.hpp"
#include "NamedPipe.hpp"

namespace plazza
{

  class Scrapper
  {
  public:
    Scrapper(void){};
    Scrapper(Order *order);
    virtual ~Scrapper(void){};

  public:
    bool          initBuffer(void);
    void          dispMatch(std::string const& buffer);
    void          dispResult(std::string const& str);

  public:
    void          dispIp(std::string const& buffer);
    std::string   nb255(std::string const& buffer, size_t& i);

  public:
    void          dispPhone(std::string const& buffer);
    std::string   nbXX(std::string const& buffer, size_t& i);

  public:
    void          dispEmail(std::string const& buffer);
    std::string   beforeAt(std::string const& buffer, size_t i);
    std::string   afterAt(std::string const& buffer, size_t i);

  public:
    bool          scpNormal(void);
    bool          scpXor(void);
    bool          scpCaesar(void);

  public:
    std::string   decryptXOR(const std::string& str, const std::string& key);
    std::string   decryptCaesar(const std::string& str, const std::string& key);

  private:
    Order*        _order;
    NamedPipe     _np;
    std::string   _buffer = "";
    std::string   _printable = "0123456789abcdefghijklmnopqrstuvwxyz_-.";

  private:
    std::vector<std::function<bool (void)>>                                     _scrapperFct;
    std::unordered_map<std::string, std::function<void (std::string const&)>>   _typeFct;
  };

}

#endif
