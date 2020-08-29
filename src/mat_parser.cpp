#include "mat_parser.h"

#include <algorithm>

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
    text[i] = line;
  }
  return text;
}

matrix::Mat textToMat(const std::vector<std::string> &text) {
  std::for_each(text.begin(), text.end(), [](std::string &str) {
    auto newEnd = std::remove_if(str.begin(), str.end(),
                                 [](char c) { return c == ' ' || c == '\t'; });
    str.erase(++newEnd, str.end());
  });
}
} // namespace mat_parser