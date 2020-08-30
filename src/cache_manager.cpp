#include "cache_manager.h"

#include "bmp_tester.hpp"

#include <fstream>
#include <vector>

namespace cache_manager {
bool isValidFile(const std::string &path) {
  std::ifstream in(path);
  if (!in) {
    return false;
  }
  in.close();
  return true;
}

std::vector<std::string> readFileLines(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> lines;
  std::string str;
  while (getline(in, str)) {
    lines.push_back(str);
  }
  return lines;
}

void addMatrices(const std::string &inputfile1, const std::string &inputfile2,
                 const std::string &outputfile) {
  if (!isValidFile(inputfile1) || !isValidFile(inputfile2)) {
    // error
  } else {
    std::vector<std::string> input1 = readFileLines()
  }
}

void multiplyMatrices(const std::string &inputfile1,
                      const std::string &inputfile2,
                      const std::string &outputfile);

void rotateImage(const std::string &inputfile, const std::string &outputfile);

void convertImage(const std::string &inputfile, const std::string &outputfile);

void hash(const std::string &algorithm, const std::string &inputfile,
          const std::string &outputfile);

void clearCache();

void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile1, const std::string &inputfile2,
                   const std::string &outputfile);

void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile, const std::string &outputfile);

} // namespace cache_manager