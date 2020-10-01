#pragma once

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string.h>
#include <string>
#include <vector>

#include "cache_manager.h"
#include "exceptions.h"

#define SIZE_OF_1_INPUT 2
#define SIZE_OF_2_INPUTS 3

namespace cache {

class Cache {
private:
  std::string m_fileName;
  int m_numOfArgs;
  std::string getResult(const std::vector<std::string> &cacheFile,
                        const std::vector<std::string> &input) const;

public:
  /**
   * @brief Construct a new Cache object
   *
   * @param fileName the name of the file where the cache stores the information
   * @param numOfArgs the number of arguments that a function of the cache gets
   */
  Cache(const std::string &fileName, const int &numOfArgs);

  /**
   * @brief save the given information in the cache
   *
   * @param function the name of the function that will be saved
   * @param fileNames the name of the input and output files
   */
  void save(std::string function,
            const std::vector<std::string> &fileNames) const;

  /**
   * @brief a method to search information in the cache
   *
   * @param function the name of the function that is being searched
   * @param inputs the input files
   * @return std::string the name of the result file if there is, and an empty
   * string if the information is not found in the cache
   */
  std::string search(const std::string &function,
                     const std::vector<std::string> &inputs) const;

  /**
   * @brief a method to clear the cache
   *
   */
  void clear();
};

} // namespace cache
