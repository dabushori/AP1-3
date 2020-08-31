#include "Mat.h"

#include <string>
#include <vector>

namespace mat_parser {

/**
 * @brief delete all the spaces (spacebar and tabs) in a given string
 *
 * @param str the given string
 */
void deleteSpaces(std::string &str);

/**
 * @brief convert a matrix into text file format (will return a vector of
 * strings which are the lines of the file)
 *
 * @param matrix the given matrix
 * @return std::vector<std::string> the lines of the file that represent the
 * given matrix
 */
std::vector<std::string> matToText(const matrix::Mat &matrix);

/**
 * @brief convert a text file into a Mat object
 *
 * @param text the text file (as a string vector which has the lines of the text
 * file in it)
 * @return matrix::Mat the matrix that was in the text file
 */
matrix::Mat textToMat(const std::vector<std::string> &text);
} // namespace mat_parser