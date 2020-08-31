#include "mat_parser.h"

#include <algorithm>
#include <iostream>
#include <regex>

namespace mat_parser {
std::vector<std::string> matToText(const matrix::Mat &matrix) {
  std::vector<std::string> text;
  for (uint32_t i = 0; i < matrix.getHeight(); ++i) {
    std::string line = "";
    for (uint32_t j = 0; j < matrix.getWidth(); ++j) {
      line.append(std::to_string(matrix(i, j)));
      if (j != matrix.getWidth() - 1) {
        line.append(",");
      }
    }
    text.push_back(line);
  }
  return text;
}

void deleteSpaces(std::string &str) {
  for (std::size_t i = 0; i < str.size(); ++i) {
    if (str[i] == ' ' || str[i] == '\t') {
      str.erase(i);
    }
  }
}

matrix::Mat textToMat(const std::vector<std::string> &text) {
  std::vector<std::string> copy = text;
  for (auto it = copy.begin(); it != copy.end(); ++it) {
    deleteSpaces(*it);
    std::string line = *it;
  }

  uint32_t height = text.size(),
           width = std::count_if(text[0].begin(), text[0].end(),
                                 [](const char &c) { return c == ','; }) +
                   1;

  for (std::string line : text) {
    uint32_t numOfvals = std::count_if(line.begin(), line.end(),
                                       [](const char &c) { return c == ','; }) +
                         1;
    if (numOfvals != width) {
      throw exceptions::CacheException(
          "the matrix file is not in the right format (the matrix rows are not "
          "in the same size)");
    }
  }

  matrix::Mat matrix(height, width);
  for (uint32_t i = 0; i < height; ++i) {
    std::string line = text[i];
    int start = 0, end = 0;
    for (uint32_t j = 0; j < width; ++j) {
      end = line.find_first_of(',', start);
      std::string val = line.substr(start, end - start);
      matrix.setValue(i, j, std::stod(val));
      start = end + 1;
    }
  }
  return matrix;
}
} // namespace mat_parser