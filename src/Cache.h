#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

#define MATCACHE_PATH "src/bin/cache/mat_cache"
#define IMAGECACHE_PATH "src/bin/cache/image_cache"
#define HASHCACHE_PATH "src/bin/cache/hash_cache"


namespace cache {

class Cache {
private:
  std::string m_fileName;
  int m_numOfArgs;

public:
  Cache(const std::string &fileName, int numOfArgs);
  void save(std::string function, const std::vector<std::string> &fileNames) const;
  std::string search(const std::vector<std::string> &inputs) const;
  void clear() const;
};

}
