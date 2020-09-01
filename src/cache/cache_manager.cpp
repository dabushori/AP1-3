#include "cache_manager.h"

#include "Cache.h"
#include "bmp_tester.hpp"
#include "crc32.h"
#include "mat_parser.h"
#include "matrix.h"

#include <filesystem>
#include <string>
#include <vector>

#define DEFAULT_RESULT_FILE "default_result_file.txt"

namespace cache_manager {
std::vector<std::string> readFileLines(const std::string &filename) {
  std::ifstream in(filename);
  if (!in) {
    in.close();
    throw exceptions::CacheException("error while opening the file " +
                                     filename);
  }
  std::vector<std::string> lines;
  std::string str;
  while (getline(in, str)) {
    lines.push_back(str);
  }
  in.close();
  return lines;
}

void addMatrices(const std::string &lmatrix, const std::string &rmatrix,
                 const std::string &output) {
  cache::Cache cache(MATCACHE_PATH, 2);

  std::vector<std::string> inputs;
  inputs.push_back(lmatrix);
  inputs.push_back(rmatrix);

  auto result = cache.search("add", inputs);

  if (result == "") {
    matrix::matrix left = mat_parser::textToMat(readFileLines(lmatrix));
    matrix::matrix right = mat_parser::textToMat(readFileLines(rmatrix));
    matrix::matrix resultMat = left + right;

    auto toSave = inputs;

    if (output == "stdout") {

      std::ofstream out(DEFAULT_RESULT_FILE, std::ios::trunc);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while opening the default file to save the result in cache");
      }

      for (uint32_t i = 0; i < resultMat.getHeight(); ++i) {
        for (uint32_t j = 0; j < resultMat.getWidth(); ++j) {
          std::cout << resultMat(i, j);
          out << resultMat(i, j);
          if (j != resultMat.getWidth() - 1) {
            std::cout << ",";
            out << ",";
          }
        }
        std::cout << std::endl;
        out << std::endl;
      }

      out.close();
      toSave.push_back(DEFAULT_RESULT_FILE);

    } else {
      std::ofstream out(output);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while trying to write to the file " + output);
      }
      for (uint32_t i = 0; i < resultMat.getHeight(); ++i) {
        for (uint32_t j = 0; j < resultMat.getWidth(); ++j) {
          out << resultMat(i, j);
          if (j != resultMat.getWidth() - 1) {
            out << ",";
          }
        }
        out << std::endl;
      }
      out.close();

      toSave.push_back(output);
    }

    cache.save("add", toSave);

  } else {

    std::cout << "got it from cache" << std::endl;

    auto fileLines = readFileLines(result);
    if (output == "stdout") {
      for (std::string line : fileLines) {
        std::cout << line << std::endl;
      }
    } else {
      std::ofstream out(output);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while trying to write to the file " + output);
      }
      for (std::string line : fileLines) {
        out << line << std::endl;
      }
      out.close();
    }
  }
}
void multMatrices(const std::string &lmatrix, const std::string &rmatrix,
                  const std::string &output) {
  cache::Cache cache(MATCACHE_PATH, 2);

  std::vector<std::string> inputs;
  inputs.push_back(lmatrix);
  inputs.push_back(rmatrix);

  auto result = cache.search("mult", inputs);

  if (result == "") {
    matrix::matrix left = mat_parser::textToMat(readFileLines(lmatrix));
    matrix::matrix right = mat_parser::textToMat(readFileLines(rmatrix));
    matrix::matrix resultMat = left * right;

    auto toSave = inputs;

    if (output == "stdout") {

      std::ofstream out(DEFAULT_RESULT_FILE, std::ios::trunc);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while opening the default file to save the result in cache");
      }

      for (uint32_t i = 0; i < resultMat.getHeight(); ++i) {
        for (uint32_t j = 0; j < resultMat.getWidth(); ++j) {
          std::cout << resultMat(i, j);
          out << resultMat(i, j);
          if (j != resultMat.getWidth() - 1) {
            std::cout << ",";
            out << ",";
          }
        }
        std::cout << std::endl;
        out << std::endl;
      }

      out.close();
      toSave.push_back(DEFAULT_RESULT_FILE);

    } else {
      std::ofstream out(output);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while trying to write to the file " + output);
      }
      for (uint32_t i = 0; i < resultMat.getHeight(); ++i) {
        for (uint32_t j = 0; j < resultMat.getWidth(); ++j) {
          out << resultMat(i, j);
          if (j != resultMat.getWidth() - 1) {
            out << ",";
          }
        }
        out << std::endl;
      }
      out.close();

      toSave.push_back(output);
    }
    cache.save("mult", toSave);

  } else {
    auto fileLines = readFileLines(result);
    if (output == "stdout") {
      for (std::string line : fileLines) {
        std::cout << line << std::endl;
      }
    } else {
      std::ofstream out(output);
      if (!out) {
        out.close();
        throw exceptions::CacheException(
            "error while trying to write to the file " + output);
      }
      for (std::string line : fileLines) {
        out << line << std::endl;
      }
      out.close();
    }
  }
}

void rotateImage(const std::string &input, const std::string &output) {
  cache::Cache cache(IMAGECACHE_PATH, 1);

  std::vector<std::string> inputs;
  inputs.push_back(input);

  auto result = cache.search("rotate", inputs);

  if (result == "") {
    testing::bmp::rotate_image(input, output);
    auto toSave = inputs;
    toSave.push_back(output);
    cache.save("rotate", toSave);
  } else {
    std::ifstream in(result);
    if (!in) {
      in.close();
      throw exceptions::CacheException("error while opening the file " +
                                       result);
    }
    auto content = std::vector<char>{std::istreambuf_iterator<char>{in},
                                     std::istreambuf_iterator<char>{}};

    in.close();

    std::ofstream out(output, std::ios::trunc | std::ios::binary);
    if (!out) {
      out.close();
      throw exceptions::CacheException(
          "error while trying to write to the file " + output);
    }

    for (auto byte : content) {
      out << byte;
    }

    out.close();
  }
}
void convertImageToGrayscale(const std::string &input,
                             const std::string &output) {
  cache::Cache cache(IMAGECACHE_PATH, 1);

  std::vector<std::string> inputs;
  inputs.push_back(input);

  auto result = cache.search("convert", inputs);

  if (result == "") {
    testing::bmp::convert_to_grayscale(input, output);
    auto toSave = inputs;
    toSave.push_back(output);
    cache.save("convert", toSave);
  } else {
    std::ifstream in(result);
    if (!in) {
      in.close();
      throw exceptions::CacheException("error while opening the file " +
                                       result);
    }
    auto content = std::vector<char>{std::istreambuf_iterator<char>{in},
                                     std::istreambuf_iterator<char>{}};

    in.close();

    std::ofstream out(output, std::ios::trunc | std::ios::binary);
    if (!out) {
      out.close();
      throw exceptions::CacheException(
          "error while trying to write to the file " + output);
    }

    for (auto byte : content) {
      out << byte;
    }

    out.close();
  }
}

uint32_t calculateFileCRC32(const std::string &filename) {
  std::ifstream in(filename, std::ios::binary);
  if (!in) {
    in.close();
    throw exceptions::CacheException("error while opening file " + filename);
  }

  std::vector<unsigned char> data((std::istream_iterator<unsigned char>(in)),
                                  (std::istream_iterator<unsigned char>()));
  in.close();
  return calculate_crc32c(0, data.data(), data.size());
}

void hash(const std::string &input, const std::string &output) {
  auto result = hash(input);
  if (output == "stdout") {
    std::cout << result << std::endl;
  } else {
    std::ofstream out(output, std::ios::trunc);
    if (!out) {
      out.close();
      throw exceptions::CacheException(
          "error while trying to write to the file " + output);
    }
    out << result;
    out.close();
  }
}

uint32_t hash(const std::string &input) {
  cache::Cache cache(HASHCACHE_PATH, 1);

  std::vector<std::string> inputs;
  inputs.push_back(input);

  auto result = cache.search("crc32", inputs);

  if (result == "") {
    auto resultHash = calculateFileCRC32(input);

    std::ofstream out(DEFAULT_RESULT_FILE, std::ios::trunc);
    if (!out) {
      out.close();
      throw exceptions::CacheException(
          "error while opening the default file to save the result in cache");
    }

    out << resultHash;

    out.close();

    auto toSave = inputs;
    toSave.push_back(DEFAULT_RESULT_FILE);

    cache.save("crc32", toSave);

    return resultHash;
  }

  std::ifstream in(result);
  std::string line;
  if (!in || !std::getline(in, line)) {
    in.close();
    throw exceptions::CacheException("error while reading the file " + result);
  }
  return std::stoi(line);
}

void clearCache() {
  if (!std::filesystem::is_empty("src/bin/cache")) {
    cache::Cache matCache(MATCACHE_PATH, 2);
    matCache.clear();
  }
}

void searchInMatrixCache(const std::string &function,
                         const std::string &lmatrix,
                         const std::string &rmatrix) {
  cache::Cache cache(MATCACHE_PATH, 2);
  std::vector<std::string> inputs;
  inputs.push_back(lmatrix);
  inputs.push_back(rmatrix);
  auto result = cache.search(function, inputs);
  if (result == "") {
    std::cout << "result didn't found in cache" << std::endl;
  } else {
    std::cout << "result found in cache" << std::endl;
  }
}
void searchInImageCache(const std::string &function, const std::string &input) {
  cache::Cache cache(IMAGECACHE_PATH, 1);
  std::vector<std::string> inputs;
  inputs.push_back(input);
  auto result = cache.search(function, inputs);
  if (result == "") {
    std::cout << "result didn't found in cache" << std::endl;
  } else {
    std::cout << "result found in cache" << std::endl;
  }
}
void searchInHashCache(const std::string &function, const std::string &input) {
  cache::Cache cache(HASHCACHE_PATH, 1);
  std::vector<std::string> inputs;
  inputs.push_back(input);
  auto result = cache.search(function, inputs);
  if (result == "") {
    std::cout << "result didn't found in cache" << std::endl;
  } else {
    std::cout << "result found in cache" << std::endl;
  }
}
} // namespace cache_manager