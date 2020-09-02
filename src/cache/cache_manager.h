#pragma once

#include <string>

namespace cache_manager {
/**
 * @brief add 2 matrices using the cache
 *
 * @param lmatrix path to the left matrix
 * @param rmatrix path to the right matrix
 * @param output path to the result file
 */
void addMatrices(const std::string &lmatrix, const std::string &rmatrix,
                 const std::string &output);

/**
 * @brief multiply 2 matrices using the cache
 *
 * @param lmatrix path to the left matrix
 * @param rmatrix path to the right matrix
 * @param output path to the result file
 */
void multMatrices(const std::string &lmatrix, const std::string &rmatrix,
                  const std::string &output);

/**
 * @brief rotates a bmp image using the cache
 *
 * @param input path to the input image
 * @param output path ot the rotated image
 */
void rotateImage(const std::string &input, const std::string &output);

/**
 * @brief converts a bmp image to grayscale using the cache
 *
 * @param input path to the input image
 * @param output path ot the converted image
 */
void convertImageToGrayscale(const std::string &input,
                             const std::string &output);

/**
 * @brief calculate file's hash using crc32 algorithm
 *
 * @param filename path to the given file
 * @return uint32_t the file's hash
 */
uint32_t calculateFileCRC32(const std::string &filename);

/**
 * @brief calculate file's hash using cache
 *
 * @param input path to the given file
 * @param output path to the file which the result will be written to
 */
void hash(const std::string &input, const std::string &output);

/**
 * @brief calculate file's hash using cache
 *
 * @param input path to the given file
 * @return uint32_t the file's hash
 */
uint32_t hash(const std::string &input);

/**
 * @brief a method to clear the cache
 *
 */
void clearCache();

/**
 * @brief a method to search information in the matrix cache
 *
 * @param function the function that is being searched
 * @param lmatrix the left matrix
 * @param rmatrix the right matrix
 */
void searchInMatrixCache(const std::string &function,
                         const std::string &lmatrix,
                         const std::string &rmatrix);

/**
 * @brief a method to search information in the image cache
 *
 * @param function the function that is being searched
 * @param input the input
 */
void searchInImageCache(const std::string &function, const std::string &input);

/**
 * @brief a method to search information in the hash cache
 *
 * @param function the function that is being searched
 * @param input the input
 */
void searchInHashCache(const std::string &function, const std::string &input);
} // namespace cache_manager