#include "cache_manager.h"

#include "bmp_tester.hpp"
#include "cache.h"
#include "mat_parser.h"

#include <fstream>
#include <iostream>
#include <vector>

namespace cache_manager {
bool isValidFile(const std::string &path) {
  std::ifstream in(path);
  if (!in) {
    return false;
  }
  in.close();
  return true;
}

std::vector<std::string> readFileLines(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> lines;
  std::string str;
  while (getline(in, str)) {
    lines.push_back(str);
  }
  return lines;
}

void addMatrices(const std::string &inputfile1, const std::string &inputfile2,
                 const std::string &outputfile) {
  if (!isValidFile(inputfile1) || !isValidFile(inputfile2)) {
    // error
  } else {
    std::vector<std::string> input1 = readFileLines(inputfile1);
    std::vector<std::string> input2 = readFileLines(inputfile2);
    for (auto it = input1.begin(); it != input1.end(); ++it) {
      mat_parser::deleteSpaces(*it);
    }
    for (auto it = input2.begin(); it != input2.end(); ++it) {
      mat_parser::deleteSpaces(*it);
    }
    std::vector<std::string> input;
    input.push_back("add");
    input.push_back("lmatrix:");
    for (auto it = input1.begin(); it != input1.end(); ++it) {
      input.push_back(*it);
    }
    input.push_back("rmatrix:");
    for (auto it = input2.begin(); it != input2.end(); ++it) {
      input.push_back(*it);
    }

    cache::MatCache cache("OurMatCache.txt"); // need file name
    auto result = cache.search(input);
    if (result == std::vector<std::string>()) {
      matrix::Mat res;
      matrix::Mat lmatrix = mat_parser::textToMat(input1);
      matrix::Mat rmatrix = mat_parser::textToMat(input2);
      try {
        res = lmatrix.add(rmatrix);
        result = mat_parser::matToText(res);

        auto solution = input;
        for (auto it = result.begin(); it != result.end(); ++it) {
          solution.push_back(*it);
        }

        cache.save(solution);

      } catch (const std::exception &e) {
        // error
      }
    }

    if (outputfile == "stdout") {
      for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << std::endl;
      }
    } else {
      std::ofstream out(outputfile, std::ios::trunc);
      if (!out) {
        // error
      }
      for (auto it = result.begin(); it != result.end(); ++it) {
        out << *it << std::endl;
      }
      if (!out) {
        // error
      }
    }
  }
}

void multiplyMatrices(const std::string &inputfile1,
                      const std::string &inputfile2,
                      const std::string &outputfile) {
  if (!isValidFile(inputfile1) || !isValidFile(inputfile2)) {
    // error
  } else {
    std::vector<std::string> input1 = readFileLines(inputfile1);
    std::vector<std::string> input2 = readFileLines(inputfile2);
    for (auto it = input1.begin(); it != input1.end(); ++it) {
      mat_parser::deleteSpaces(*it);
    }
    for (auto it = input2.begin(); it != input2.end(); ++it) {
      mat_parser::deleteSpaces(*it);
    }
    std::vector<std::string> input;
    input.push_back("mult");
    input.push_back("lmatrix:");
    for (auto it = input1.begin(); it != input1.end(); ++it) {
      input.push_back(*it);
    }
    input.push_back("rmatrix:");
    for (auto it = input2.begin(); it != input2.end(); ++it) {
      input.push_back(*it);
    }

    cache::MatCache cache("OurMatCache.txt"); // need file name
    auto result = cache.search(input);
    if (result == std::vector<std::string>()) {
      matrix::Mat res;
      matrix::Mat lmatrix = mat_parser::textToMat(input1);
      matrix::Mat rmatrix = mat_parser::textToMat(input2);
      try {
        res = lmatrix.multiplyMatrices(rmatrix);
        result = mat_parser::matToText(res);

        auto solution = input;
        for (auto it = result.begin(); it != result.end(); ++it) {
          solution.push_back(*it);
        }

        cache.save(solution);

      } catch (const std::exception &e) {
        // error
      }
    }

    if (outputfile == "stdout") {
      for (auto it = result.begin(); it != result.end(); ++it) {
        std::cout << *it << std::endl;
      }
    } else {
      std::ofstream out(outputfile, std::ios::trunc);
      if (!out) {
        // error
      }
      for (auto it = result.begin(); it != result.end(); ++it) {
        out << *it << std::endl;
      }
      if (!out) {
        // error
      }
    }
  }
}

void rotateImage(const std::string &inputfile, const std::string &outputfile) {
  cache::ImageCache cache("OurImageCache.txt"); // need file name
  std::vector<std::string> input;
  input.push_back(inputfile);

  auto result = cache.search(input);

  if (result == std::vector<std::string>()) {
    testing::bmp::rotate_image(inputfile, outputfile);
  } else {
    std::ofstream out(outputfile, std::ios::trunc);
    std::ifstream in(result[0]);
    if (!in || !out) {
      // error
    }
    auto info = std::vector<char>{std::istreambuf_iterator<char>{in},
                                  std::istreambuf_iterator<char>{}};
    for (auto it = info.begin(); it != info.end(); ++it) {
      out << *it;
    }
    if (!out) {
      // error
    }
  }
}

void convertImage(const std::string &inputfile, const std::string &outputfile) {
  cache::ImageCache cache("OurImageCache.txt"); // need file name
  std::vector<std::string> input;
  input.push_back(inputfile);

  auto result = cache.search(input);

  if (result == std::vector<std::string>()) {
    testing::bmp::convert_to_grayscale(inputfile, outputfile);
  } else {
    std::ofstream out(outputfile, std::ios::trunc);
    std::ifstream in(result[0]);
    if (!in || !out) {
      // error
    }
    auto info = std::vector<char>{std::istreambuf_iterator<char>{in},
                                  std::istreambuf_iterator<char>{}};
    for (auto it = info.begin(); it != info.end(); ++it) {
      out << *it;
    }
    if (!out) {
      // error
    }
  }
}

void hash(const std::string &algorithm, const std::string &inputfile,
          const std::string &outputfile);

void clearCache();

void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile1, const std::string &inputfile2,
                   const std::string &outputfile);

void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile, const std::string &outputfile);

} // namespace cache_manager