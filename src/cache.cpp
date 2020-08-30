#include "cache.h"

namespace cache {

Cache::Cache(const std::string &fileName) { m_fileName = fileName; }

MatCache::MatCache() : Cache("matCache.txt"){};

ImageCache::ImageCache() : Cache("imageCache/"){};

std::vector<std::string> MatCache::getResult(const std::vector<std::string> &cache,
                                   const std::vector<std::string> &input) const {

  if (cache.size() < input.size()) {
    return std::vector<std::string>();
  }

  uint32_t resultStart = 0;
  bool found = false;
  for (auto i = 0; i < cache.size(); ++i) {
    if (!found && cache[i] == input[0]) {
      for (auto j = 0; j < input.size(); ++j) {
        if (i + j >= cache.size()) {
          return std::vector<std::string>();
        }
        if (cache[i + j] != input[j]) {
          found = false;
          break;
        }
        found = true;
      }
      if (found) {
        resultStart = i + input.size();
        break;
      }
    }
  }

  if (!found) {
    return std::vector<std::string>();
  }

  std::regex regex("(mult|add)");
  std::vector<std::string> result;
  uint32_t index = resultStart + 1;
  std::string line = cache[index];
  while (!std::regex_match(line, regex) && index < cache.size()) {
    result.push_back(line);
    ++index;
    line = cache[index];
  }

  return result;
}

void MatCache::save(const std::vector<std::string> &lines) const {
  std::string path = MATCACHE_PATH;
  path.append(m_fileName);
  std::ofstream out(path, std::ios::trunc);
  if (!out) {
    // error
  }
  for (auto it = lines.begin(); it != lines.end(); ++it) {
    out << *it << std::endl;
  }
  if (!out) {
    // error
  }
  out.close();
}

void MatCache::clear() const {
  std::string path = MATCACHE_PATH;
  path.append(m_fileName);
  std::ifstream clear(path);
  if (!clear.good()) {
    return;
  }
  if (remove(path.c_str()) != 0) {
    // error
  }
}

std::vector<std::string> MatCache::search(const std::vector<std::string> &lines) const {
  std::string path = MATCACHE_PATH;
  path.append(m_fileName);
  std::ifstream in(path);
  if (!in) {
    // error
  }
  std::vector<std::string> cacheLines;
  std::string str;
  while (getline(in, str)) {
    cacheLines.push_back(str);
  }
  if (!in) {
    // error
  }
  std::vector<std::string> result = getResult(cacheLines, lines);
  return result;
}

void ImageCache::clear() const {
  std::string path = IMAGECACHE_PATH;
  path.append(m_fileName);
  std::ifstream clear(path);
  if (!clear.good()) {
    return;
  }
  std::vector<std::string> fileLines;
  std::string str;
  while (getline(clear, str)) {
    fileLines.push_back(str);
  }
  std::for_each(fileLines.begin(), fileLines.end(), [](std::string &str) {
    std::string path = IMAGECACHE_PATH;
    std::string imageName = path + str;
    if (remove(imageName.c_str()) != 0) {
      // error
    }
  });
  if (remove(path.c_str()) != 0) {
    // error
  }
}

  std::vector<std::string> ImageCache::search(const std::vector<std::string> &lines) const {
    std::ifstream file(lines[0]);
    auto info = std::vector<char>{std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{}};
    
    
    for (auto it = info.begin(); it != info.end(); ++it) {

    }
  }



} // namespace cache