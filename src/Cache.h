#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

#define MATCACHE_PATH "src/bin/cache/mat_cache"
#define MATCACHE_PATH "src/bin/cache/image_cache"
#define MATCACHE_PATH "src/bin/cache/hash_cache"


namespace cache {

class Cache {
private:
  std::string m_fileName;
  int m_numOfArgs;

public:
  Cache(const std::string &fileName);
  virtual void save(const std::vector<std::string> &lines) const =0;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const = 0;
  virtual void clear() const = 0;
};

}
