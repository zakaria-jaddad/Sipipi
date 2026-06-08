#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iomanip>

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return EXIT_FAILURE;
  }
  BitcoinExchange btc;
  if (btc.parseDataBase("data.csv") == false) {
    return EXIT_FAILURE;
  }

  // ---- input file

  std::ifstream inputFile(argv[1]);

  if (inputFile.is_open() == false) {
    std::cerr << "Error: could not open file." << std::endl;
    return EXIT_FAILURE;
  }

  // Reading csv lines
  std::string inputLine;

  // get first line
  if (!std::getline(inputFile, inputLine)) {
    std::cerr << "Error: no valid csv header found in file: " << argv[1]
              << std::endl;
  }
  // a function named getKeyValuePair returns an std pair
  std::pair<std::string, std::string> inputheaderPair =
      getKeyValuePair(inputLine, "|");
  if (inputheaderPair.first.empty() == true &&
      inputheaderPair.second.empty() == true) {
    return EXIT_FAILURE;
  }
  if (inputheaderPair.first != "date" || inputheaderPair.second != "value") {
    std::cerr << "'" << inputheaderPair.first << "'" << " " << "'"
              << inputheaderPair.second << "'" << std::endl;
    std::cerr << "No date or value header provided" << std::endl;
    return EXIT_FAILURE;
  }

  std::map<std::string, float> btcCount;

  while (std::getline(inputFile, inputLine)) {
    std::pair<std::string, std::string> btcPair =
        getKeyValuePair(inputLine, "|");
    if (btcPair.first.empty() == true && btcPair.second.empty() == true) {
      continue;
    }
    if (isValidDate(btcPair.first) == false) {
      std::cerr << "Error bad input => " << btcPair.first << std::endl;
      continue;
    }
    if (isValidValue(btcPair.second) == false) {
      std::cerr << "Error bad input => " << btcPair.second << std::endl;
      continue;
    }

    std::stringstream ss(btcPair.second);
    double btcPrice;
    ss >> btcPrice;

    if (btcPrice > 1000) {
      std::cerr << "Error: too large a number." << std::endl;
      continue;
    }
    if (btcPrice < 0) {
      std::cerr << "Error: not a positive number." << std::endl;
      continue;
    }
    std::string date = btcPair.first;
    std::string value = btcPair.second;
    std::map<std::string, float> btcDataBase = btc.getBtcDataBase();

    std::map<std::string, float>::iterator it = btcDataBase.lower_bound(date);
    if (it != btcDataBase.end() && it->first == date) {
      std::cout << it->first << " => " << value << " = " << std::fixed
                << it->second * btcPrice << std::endl;
      continue;
    }
    if (it != btcDataBase.begin()) {
      --it;
      std::cout << it->first << " => " << value << " = "
                << it->second * btcPrice << std::endl;
      continue;
    }
    else {
      std::cout << it->first << " => " << value << " = "
                << it->second * btcPrice << std::endl;
      continue;
    }
  }

  return 0;
}
