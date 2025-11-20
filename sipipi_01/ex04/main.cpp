#include <fcntl.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    std::cout << "./prog <filename> <s1> <s2>\n";
    return 1;
  }

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  std::string output_filename = filename + ".replace";
  std::ifstream file_input(filename.c_str(), std::ios::in);
  if (file_input.is_open() == false) {
    std::cout << "File Not Found\n";
    return 1;
  }
  std::ofstream file_output(output_filename.c_str());
  if (!file_output) {
    std::cerr << "Error: Could not create output file\n";
    return 1;
  }

  std::string line;
  while (std::getline(file_input, line)) {
    if (line.find('\n') != std::string::npos) {
      line += "\n";
    }

    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
      line.erase(pos, s1.length());
      line.insert(pos, s2);
      pos += s2.length();
    }
    file_output << line << '\n';
  }
  file_input.close();
  file_output.close();
  return 0;
}
