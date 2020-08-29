#include "Mat.h"

#include <vector>
#include <string>

namespace mat_parser {
    std::vector<std::string> matToText(const matrix::Mat& matrix);
    matrix::Mat textToMat(const std::vector<std::string>& text);
}