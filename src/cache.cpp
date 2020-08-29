#include "cache.h"

namespace cache {

Cache::Cache(const std::string &fileName) { m_fileName = fileName; }

MatCache::MatCache(const std::string &fileName) : Cache(fileName){};

void MatCache::save(const std::vector<std::string> &lines) const {
  std::string path = ""; // need the path
  path.append(m_fileName);
  std::ofstream out(path, std::ios::trunc);
  if (!out) {
    // error
  }
  for (auto it = lines.begin(); it != lines.end(); ++it) {
    out << *it << std::endl;
  }
}

void MatCache::clear() const {
  std::string path = ""; // need the path
  path.append(m_fileName);
  if (remove(path.c_str()) != 0) {
    // error
  }
}

std::vector<std::string>
MatCache::search(const std::vector<std::string> &lines) const {
  std::string path = ""; // need the path
  path.append(m_fileName);
  std::ofstream out(path, std::ios::trunc);
}

} // namespace cache