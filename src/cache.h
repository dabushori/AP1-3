#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>
#include <regex>

#define MATCACHE_PATH "src/bin/cache/matCache.txt"
#define IMAGECACHE_PATH "src/bin/cache/imageCache/"


namespace cache {

class Cache {
protected:
  std::string m_fileName;

public:
  Cache(const std::string &fileName);
  virtual void save(const std::vector<std::string> &lines) const =0;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const = 0;
  virtual void clear() const = 0;
};

class MatCache : public Cache {
private:
  std::vector<std::string> getResult(const std::vector<std::string> &cache, const std::vector<std::string> &input) const;
public:
  // constructor
  MatCache();
  virtual void save(const std::vector<std::string> &lines) const override;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const override;
  virtual void clear() const override;
};

class ImageCache : public Cache {
public:
  // constructor
  ImageCache();
  virtual void save(const std::vector<std::string> &lines) const override;
  virtual std::vector<std::string>
  search(const std::vector<std::string> &lines) const override;
  virtual void clear() const override;
};
} // namespace cache