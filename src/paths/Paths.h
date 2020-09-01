#pragma once

#include <string>

namespace paths {
class Paths {

  friend std::string getMatCachePath();
  friend std::string getImageCachePath();
  friend std::string getHashCachePath();
  friend std::string getInsideCachePath();
  friend std::string getDefaultResultFilePath();

private:
  std::string m_matCachePath;
  std::string m_imageCachePath;
  std::string m_hashCachePath;
  std::string m_insideCachePath;
  std::string m_defaultResultFilePath;

public:
  Paths(const std::string &workingDirectory);
};

std::string getMatCachePath();
std::string getImageCachePath();
std::string getHashCachePath();
std::string getInsideCachePath();
std::string getDefaultResultFilePath();
} // namespace paths