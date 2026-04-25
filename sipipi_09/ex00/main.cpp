#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

std::pair<std::string, std::string> getKeyValuePair(std::string &line,
                                                    std::string delim) {
  size_t pos = line.find(delim);

  if (pos == std::string::npos) {
    std::cerr << "Error: no " << delim << "found in line: " << line
              << std::endl;
    return std::make_pair("", "");
  }

  std::string key;
  std::string value;

  key = line.substr(0, pos);
  line.erase(0, pos + 1);
  value = line;

  if (value.find(",") != std::string::npos) {
    std::cerr << "Error: found extra " << delim << "in value: " << value
              << std::endl;
    return std::make_pair("", "");
  }
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
    } else if (!isdigit(strValue[i])) {
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

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cerr << "./btc <input>" << std::endl;
    return EXIT_FAILURE;
  }

  std::ifstream dataFile("data.csv");

  if (dataFile.is_open() == false) {
    std::cerr << "Error: coudn't open data.csv file" << std::endl;
    return EXIT_FAILURE;
  }

  // Reading csv lines
  std::string line;

  // get first line
  if (!std::getline(dataFile, line)) {
    std::cerr << "Error: no valid csv header found" << std::endl;
  }
  // a function named getKeyValuePair returns an std pair
  std::pair<std::string, std::string> headerPair = getKeyValuePair(line, ",");
  if (headerPair.first.empty() == true && headerPair.second.empty() == true) {
    return EXIT_FAILURE;
  }
  if (headerPair.first != "date" || headerPair.second != "exchange_rate") {
    return EXIT_FAILURE;
  }

  std::map<std::string, float> btcPrices;

  while (std::getline(dataFile, line)) {
    std::pair<std::string, std::string> btcPair = getKeyValuePair(line, ",");
    if (btcPair.first.empty() == true && btcPair.second.empty() == true) {
      return EXIT_FAILURE;
    }
    if (isValidPair(btcPair) == false) {
      return EXIT_FAILURE;
    }

    std::stringstream ss(btcPair.second);
    float btcPrice;
    ss >> btcPrice;

    // Subject specific error messages
    if (btcPrice < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      return EXIT_FAILURE;
    }

    btcPrices[btcPair.first] = btcPrice;
  }

  for (std::map<std::string, float>::const_iterator it = btcPrices.begin();
       it != btcPrices.end(); it++) {
    std::cout << "key: " << "'" << it->first << "', " << "value: '"
              << it->second << "'" << std::endl;
  }

  // ---- input file

  std::ifstream inputFile(argv[1]);

  if (inputFile.is_open() == false) {
    std::cerr << "Error: coudn't open " << argv[1] << " file" << std::endl;
    return EXIT_FAILURE;
  }

  // Reading csv lines
  std::string inputLine;

  // get first line
  if (!std::getline(dataFile, inputLine)) {
    std::cerr << "Error: no valid csv header found" << std::endl;
  }
  // a function named getKeyValuePair returns an std pair
  std::pair<std::string, std::string> inputheaderPair =
      getKeyValuePair(inputLine, "|");
  if (inputheaderPair.first.empty() == true &&
      inputheaderPair.second.empty() == true) {
    return EXIT_FAILURE;
  }
  if (inputheaderPair.first != "date" || inputheaderPair.second != "value") {
    return EXIT_FAILURE;
  }

  std::map<std::string, float> btcCount;

  while (std::getline(dataFile, inputLine)) {
    std::pair<std::string, std::string> btcPair =
        getKeyValuePair(inputLine, "|");
    if (btcPair.first.empty() == true && btcPair.second.empty() == true) {
      return EXIT_FAILURE;
    }
    if (isValidPair(btcPair) == false) {
      return EXIT_FAILURE;
    }

    std::stringstream ss(btcPair.second);
    float btcPrice;
    ss >> btcPrice;

    // Subject specific error messages
    if (btcPrice > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      return EXIT_FAILURE;
    }
    if (btcPrice < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      return EXIT_FAILURE;
    }

    btcCount[btcPair.first] = btcPrice;
  }

  return 0;
}
