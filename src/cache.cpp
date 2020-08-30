#include "cache.h"

namespace cache {

Cache::Cache(const std::string &fileName) { m_fileName = fileName; }

MatCache::MatCache(const std::string &fileName) : Cache(fileName){};

ImageCache::ImageCache(const std::string &fileName) : Cache(fileName){};

void Cache::save(const std::vector<std::string> &lines) const {
  std::string path = ""; // need the path
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
  std::string path = ""; // need the path
  path.append(m_fileName);
  std::ifstream clear(path);
  if (!clear.good()) {
    return;
  }
  if (remove(path.c_str()) != 0) {
    // error
  }
}

std::vector<std::string>
MatCache::search(const std::vector<std::string> &lines) const {
  std::string path = ""; // need the path
  path.append(m_fileName);
  if (!search) {
    // error
  }
  // function to reed lines from file
  std::ifstream in(path);
  std::vector<std::string> fileLines;
  std::string str;
  while (getline(in, str)) {
    fileLines.push_back(str);
  }
  for (auto it = fileLines.begin(); it != fileLines.end(); ++it) {
    if (lines[1].compare(*it) == 0) {
    }
  }

  //   Add / Mult
  //   lmatrix:
  //   1, 2, 3
  //   4, 5, 6
  //   7, 8, 9
  //   rmatrix:
  //   1, 2, 3
  //   4, 5, 6
  //   7, 8, 9
  //   result:
  //   1, 2, 3
  //   4, 5, 6
  //   7, 8, 9
}

void ImageCache::clear() const {
  std::string path = ""; // need the path
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
    std::string imageName = "" + str; // need a path
    if (remove(imageName.c_str()) != 0) {
      // error
    }
  });
  if (remove(path.c_str()) != 0) {
    // error
  }
}

} // namespace cache