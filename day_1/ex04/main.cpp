#include <fstream>
#include <ios>
#include <iostream>

int main(int argc, char **argv) {

  if (argc != 4) {
    std::cout << "./prog <filename> <s1> <s2>\n";
    return 1;
  }

  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  std::ifstream fi(filename.c_str(), std::ios::in);

  if (fi.is_open()) {
    std::string output_filename = filename + ".replace";
    std::ofstream fo(output_filename.c_str());
    if (fo) {
      std::cerr << "Error: Could not create output file\n";
      return 1;
    }
    std::string line;
    while (std::getline(fi, line)) {
      size_t pos = 0;
      while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos += s2.length();
      }
      fo << line << '\n';
    }
    fi.close();
    fo.close();

  } else {
    std::cout << "File Not Found\n";
    return 0;
  }
  return 0;
}
