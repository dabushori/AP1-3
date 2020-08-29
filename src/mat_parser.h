#include "Mat.h"

#include <string>
#include <vector>

namespace mat_parser {
std::vector<std::string> matToText(const matrix::Mat &matrix);
matrix::Mat textToMat(const std::vector<std::string> &text);
} // namespace mat_parser