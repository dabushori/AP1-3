#include "Paths.h"

#include <filesystem>
#include <iostream>

namespace paths {
bool hasEnding(std::string const &fullString, std::string const &ending) {
  if (fullString.length() >= ending.length()) {
    return (0 == fullString.compare(fullString.length() - ending.length(),
                                    ending.length(), ending));
  } else {
    return false;
  }
}

std::string findPathToCacheDirectory(const std::string &workingDirectory) {
  for (auto &p :
       std::filesystem::recursive_directory_iterator(workingDirectory)) {
    std::string path = p.path();
    if (hasEnding(path, "src/bin/cache")) {
      return path;
    }
  }
  return "error";
}

Paths::Paths(const std::string &workingDirectory) {
  auto cacheDirectory = findPathToCacheDirectory(workingDirectory);
  m_matCachePath = cacheDirectory + "/mat_cache.txt";
  m_imageCachePath = cacheDirectory + "/image_cache.txt";
  m_hashCachePath = cacheDirectory + "/hash_cache.txt";
  m_insideCachePath = cacheDirectory + "/";
  m_defaultResultFilePath = "default_result_file.txt";
}

std::string getMatCachePath() {
  Paths paths(std::filesystem::current_path().c_str());
  return paths.m_matCachePath;
}

std::string getImageCachePath() {
  Paths paths(std::filesystem::current_path().c_str());
  return paths.m_imageCachePath;
}

std::string getHashCachePath() {
  Paths paths(std::filesystem::current_path().c_str());
  return paths.m_hashCachePath;
}

std::string getInsideCachePath() {
  Paths paths(std::filesystem::current_path().c_str());
  return paths.m_insideCachePath;
}

std::string getDefaultResultFilePath() {
  Paths paths(std::filesystem::current_path().c_str());
  return paths.m_defaultResultFilePath;
}
} // namespace paths