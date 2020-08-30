#include "cache_manager.h"

#include "Cache.h"
#include "mat_parser.h"

#include <string>
#include <vector>

namespace cache_manager {
std::vector<std::string> readFileLines(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> lines;
  std::string str;
  while (getline(in, str)) {
    lines.push_back(str);
  }
  return lines;
}

void addMatrices(const std::string &lmatrix, const std::string &rmatrix,
                 const std::string &output) {
  cache::Cache cache(MATCACHE_PATH, 2);

  std::vector<std::string> inputs;
  inputs.push_back(lmatrix);
  inputs.push_back(rmatrix);

  auto result = cache.search(inputs);
}
void multMatrices(const std::string &lmatrix, const std::string &rmatrix,
                  const std::string &output);

void rotateImage(const std::string &input, const std::string &output);
void convertImageToGrayscale(const std::string &input,
                             const std::string &output);

void hash(const std::string &input, const std::string &output);
uint32_t hash(const std::string &input);

void clearCache();
void searchInMatrixCache(const std::string &function,
                         const std::string &lmatrix,
                         const std::string &rmatrix);
void searchInImageCache(const std::string &function, const std::string &lmatrix,
                        const std::string &rmatrix);
void searchInHashCache(const std::string &function, const std::string &lmatrix,
                       const std::string &rmatrix);
} // namespace cache_manager