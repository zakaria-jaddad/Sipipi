#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

bool isLeapYear(int year);

bool isValidDate(const std::string &date);

bool isValidValue(const std::string &strValue);

bool isValidPair(std::pair<std::string, std::string> pair);

std::string trim(const std::string &str);

std::pair<std::string, std::string> getKeyValuePair(std::string &line,
                                                    std::string delim);

class BitcoinExchange {
public:
  bool parseDataBase(const std::string filename);
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();
  const std::map<std::string, float> &getBtcDataBase() const;

private:
  std::map<std::string, float> _btcDataBase;
};
#endif // !BITCOINEXCHANGE_HPP
