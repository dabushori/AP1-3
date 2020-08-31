#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

#include "cache_manager.h"
#include "exceptions.h"

#define MATCACHE_PATH "src/bin/cache/mat_cache"
#define IMAGECACHE_PATH "src/bin/cache/image_cache"
#define HASHCACHE_PATH "src/bin/cache/hash_cache"

#define INSIDE_CACHE_PATH "src/bin/cache/"

namespace cache {

class Cache {
private:
  std::string m_fileName;
  int m_numOfArgs;
  std::string getResult(const std::vector<std::string> &cacheFile,
                        const std::vector<std::string> &input) const;

public:
  Cache(const std::string &fileName, const int &numOfArgs);
  void save(std::string function,
            const std::vector<std::string> &fileNames) const;
  std::string search(const std::string &function,
                     const std::vector<std::string> &inputs) const;
  void clear() const;
};

} // namespace cache
