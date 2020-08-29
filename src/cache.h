#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

namespace cache {

class Cache {
protected:
  std::string m_fileName;

public:
  Cache(const std::string &fileName);
  virtual void save(const std::vector<std::string> &lines) const = 0;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const = 0;
  virtual void clear() const = 0;
};

class MatCache : public Cache {
public:
  MatCache(const std::string &fileName);
  virtual void save(const std::vector<std::string> &lines) const;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const;
  virtual void clear() const;
};
} // namespace cache