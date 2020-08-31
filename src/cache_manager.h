#pragma once

#include <string>

namespace cache_manager {
void addMatrices(const std::string &lmatrix, const std::string &rmatrix,
                 const std::string &output);
void multMatrices(const std::string &lmatrix, const std::string &rmatrix,
                  const std::string &output);

void rotateImage(const std::string &input, const std::string &output);
void convertImageToGrayscale(const std::string &input,
                             const std::string &output);

uint32_t calculateFileCRC32(const std::string &filename);
void hash(const std::string &input, const std::string &output);
uint32_t hash(const std::string &input);

void clearCache();
void searchInMatrixCache(const std::string &function,
                         const std::string &lmatrix,
                         const std::string &rmatrix);
void searchInImageCache(const std::string &function, const std::string &input);
void searchInHashCache(const std::string &function, const std::string &input);
} // namespace cache_manager