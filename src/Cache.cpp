#include "Cache.h"

namespace cache {

Cache::Cache(const std::string &fileName, const int &numOfArgs) {
  m_fileName = fileName;
  m_numOfArgs = numOfArgs;
}

std::string Cache::getResult(const std::vector<std::string> &cacheFile,
                             const std::vector<std::string> &input) const {

  if (cacheFile.size() < input.size()) {
    return "";
  }

  uint32_t resultStart = 0;
  bool found = false;
  for (std::size_t i = 0; i < cacheFile.size(); ++i) {
    if (!found && cacheFile[i] == input[0]) {
      for (std::size_t j = 0; j < input.size(); ++j) {
        if (i + j >= cacheFile.size()) {
          return "";
        }
        if (cacheFile[i + j] != input[j]) {
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
    return "";
  }

  uint32_t index = resultStart + 1;
  return cacheFile[index];
}

std::string getEnding(const std::string &file) {
  auto index = file.find_last_of('.');
  std::string ending = "";
  for (auto i = index; i < file.size(); ++i) {
    ending += file[i];
  }
  return ending;
}

void Cache::save(std::string function,
                 const std::vector<std::string> &fileNames) const {
  if (fileNames.size() != static_cast<std::size_t>(m_numOfArgs + 1)) {
    throw exceptions::CacheException("Error in save - numOfArgs problem");
  }

  std::vector<std::string> newLines;
  std::string resultName;
  std::ifstream in(m_fileName);
  if (!in.good()) {
    newLines.push_back("1");
    resultName = function + "1";
  } else {
    std::string number;
    std::getline(in, number);
    resultName = function + number;
  }
  in.close();
  newLines.push_back(function);
  std::string oldResult = "";

  if (fileNames.size() == 2) {
    uint32_t input = cache_manager::hash(fileNames[0]);
    newLines.push_back(std::to_string(input));
    resultName = INSIDE_CACHE_PATH + resultName + getEnding(fileNames[1]);
    newLines.push_back(resultName);
    oldResult = fileNames[1];
  }
  if (fileNames.size() == 3) {
    uint32_t input1 = cache_manager::hash(fileNames[0]);
    uint32_t input2 = cache_manager::hash(fileNames[1]);
    newLines.push_back(std::to_string(input1));
    newLines.push_back(std::to_string(input2));
    resultName = INSIDE_CACHE_PATH + resultName + getEnding(fileNames[2]);
    newLines.push_back(resultName);
    oldResult = fileNames[2];
  } else {
    throw exceptions::CacheException("Error in save - not 2 or 3 inputs");
  }

  std::ofstream out(m_fileName, std::ios::app | std::ios::trunc);
  if (!out) {
    out.close();
    throw exceptions::CacheException(
        "Error in save - cant write in Cache file");
  }
  for (std::string str : newLines) {
    out << str << std::endl;
  }
  if (!out) {
    out.close();
    throw exceptions::CacheException(
        "Error in save - problem after we write in Cache file");
  }
  out.close();

  std::ifstream searchResult(oldResult);
  if (!searchResult) {
    searchResult.close();
    throw exceptions::CacheException(
        "Error in save - problem when we read result file");
  }
  auto content = std::vector<char>{std::istreambuf_iterator<char>{searchResult},
                                   std::istreambuf_iterator<char>{}};
  if (!searchResult) {
    searchResult.close();
    throw exceptions::CacheException(
        "Error in save - problem after we read result file");
  }
  searchResult.close();

  std::ofstream newResult(resultName, std::ios::trunc);
  if (!newResult) {
    newResult.close();
    throw exceptions::CacheException(
        "Error in save - problem when we write in the new result file");
  }
  for (char c : content) {
    newResult << c;
  }
  if (!newResult) {
    newResult.close();
    throw exceptions::CacheException(
        "Error in save - problem after we write in the new result file");
  }
  newResult.close();
}

std::string Cache::search(const std::string &function,
                          const std::vector<std::string> &inputs) const {
  if (inputs.size() != static_cast<std::size_t>(m_numOfArgs + 1)) {
    return "";
  }
  std::vector<std::string> lines = inputs;
  std::vector<std::string>::iterator it = lines.begin();
  lines.insert(it, function);

  std::ifstream in(m_fileName);
  if (!in) {
    in.close();
    throw exceptions::CacheException(
        "Error in search - cant read the Cache lines p1");
  }
  std::vector<std::string> fileLines;
  std::string str;
  while (getline(in, str)) {
    fileLines.push_back(str);
  }
  if (!in) {
    in.close();
    throw exceptions::CacheException(
        "Error in search - cant read the Cache lines p2");
  }
  in.close();

  std::string result = getResult(fileLines, lines);
  return result;
}

void Cache::clear() const { system("exec rm -r src/bin/cache/*"); }

} // namespace cache