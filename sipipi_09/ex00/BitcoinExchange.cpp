#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  this->_btcDataBase = other._btcDataBase;
};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this == &other) {
    return *this;
  }
  this->_btcDataBase = other._btcDataBase;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::parseDataBase(const std::string filename) {
  std::ifstream dataFile(filename.c_str());

  if (dataFile.is_open() == false) {
    std::cerr << "Error: couldn't open data.csv file" << std::endl;
    return false;
  }

  // Reading csv lines
  std::string line;

  // get first line
  if (!std::getline(dataFile, line)) {
    std::cerr << "Error: no valid csv header found" << std::endl;
    return false;
  }
  // a function named getKeyValuePair returns an std pair
  std::pair<std::string, std::string> headerPair = getKeyValuePair(line, ",");
  if (headerPair.first.empty() == true && headerPair.second.empty() == true) {
    return false;
  }
  if (headerPair.first != "date" || headerPair.second != "exchange_rate") {
    return false;
  }

  while (std::getline(dataFile, line)) {
    std::pair<std::string, std::string> btcPair = getKeyValuePair(line, ",");
    if (btcPair.first.empty() == true && btcPair.second.empty() == true) {
      return false;
    }
    if (isValidPair(btcPair) == false) {
      return false;
    }

    std::stringstream ss(btcPair.second);
    float btcPrice;
    ss >> btcPrice;

    if (btcPrice < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      return false;
    }

    this->_btcDataBase[btcPair.first] = btcPrice;
  }
  return true;
}

const std::map<std::string, float> &BitcoinExchange::getBtcDataBase() const {
  return this->_btcDataBase;
}

/* -- private member functions -- */

std::pair<std::string, std::string> getKeyValuePair(std::string &line,
                                                    std::string delim) {
  size_t pos = line.find(delim);

  if (pos == std::string::npos) {
    std::cerr << "Error: bad input => " << line << std::endl;
    return std::make_pair("", "");
  }

  std::string key;
  std::string value;

  key = line.substr(0, pos);
  line.erase(0, pos + 1);
  value = line;

  if (value.find(delim) != std::string::npos) {
    std::cerr << "Error: found extra " << delim << "in value: " << value
              << std::endl;
    return std::make_pair("", "");
  }
  key = trim(key);
  value = trim(value);
  return std::make_pair(key, value);
}

bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// date: YYYY-MM-DD
bool isValidDate(const std::string &date) {
  if (date.length() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;

  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 7)
      continue;
    if (!isdigit(date[i]))
      return false;
  }

  int year, month, day;

  std::stringstream ssYear(date.substr(0, 4));
  std::stringstream ssMonth(date.substr(5, 2));
  std::stringstream ssDay(date.substr(8, 2));

  ssYear >> year;
  ssMonth >> month;
  ssDay >> day;

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isLeapYear(year))
    daysInMonth[2] = 29;

  if (day > daysInMonth[month])
    return false;

  return true;
}

bool isValidValue(const std::string &strValue) {
  if (strValue.empty())
    return false;

  int dotCount = 0;
  for (size_t i = 0; i < strValue.length(); ++i) {
    if (i == 0 && (strValue[i] == '+' || strValue[i] == '-'))
      continue;
    if (strValue[i] == '.') {
      dotCount++;
      if (dotCount > 1) {
        std::cerr << "Error: valid number required: " << strValue << std::endl;
        return false;
      }
    }
    else if (!isdigit(strValue[i])) {
      std::cerr << "Error: valid number required: " << strValue << std::endl;
      return false;
    }
  }
  return true;
}

bool isValidPair(std::pair<std::string, std::string> pair) {

  if (isValidDate(pair.first) == false) {
    return false;
  }
  if (isValidValue(pair.second) == false) {
    return false;
  }
  return true;
}

std::string trim(const std::string &str) {
  size_t start = 0;
  while (start < str.length() &&
         std::isspace(static_cast<unsigned char>(str[start])))
    start++;

  size_t end = str.length();
  while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
    end--;

  return str.substr(start, end - start);
}
