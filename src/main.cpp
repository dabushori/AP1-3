#include "Paths.h"
#include "cache_manager.h"
#include "exceptions.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string.h>

void ex3Format(int argc, char **argv) {
  if (argc == 1) {
    throw exceptions::CacheException("error - didn't recieve any arguments");
  }
  if (!strcmp(argv[1], "matrix")) {
    if (argc != 6) {
      throw exceptions::CacheException(
          "matrix should have a function, two input files and one output file");
    }
    if (!strcmp(argv[2], "add")) {
      cache_manager::addMatrices(argv[3], argv[4], argv[5]);
    } else if (!strcmp(argv[2], "multiply")) {
      cache_manager::multMatrices(argv[3], argv[4], argv[5]);
    } else {
      throw exceptions::CacheException(
          "the function's name is not valid (it must be add or multiply)");
    }

  } else if (!strcmp(argv[1], "image")) {
    if (argc != 5) {
      throw exceptions::CacheException(
          "image should have a function, one input file and one output file");
    }
    if (!strcmp(argv[2], "rotate")) {
      cache_manager::rotateImage(argv[3], argv[4]);
    } else if (!strcmp(argv[2], "convert")) {
      cache_manager::convertImageToGrayscale(argv[3], argv[4]);
    } else {
      throw exceptions::CacheException(
          "the function's name is not valid (it must be rotate or convert)");
    }

  } else if (!strcmp(argv[1], "hash")) {
    if (argc != 5) {
      throw exceptions::CacheException(
          "hash should have a function, one input file and one output file");
    }
    if (!strcmp(argv[2], "crc32")) {
      cache_manager::hash(argv[3], argv[4]);
    } else {
      throw exceptions::CacheException(
          "the function's name is not valid (it must be crc32)");
    }

  } else if (!strcmp(argv[1], "cache")) {
    if (!strcmp(argv[2], "clear")) {
      if (argc != 3) {
        throw exceptions::CacheException("the format of the command is wrong "
                                         "(should be 'ex3.out cache clear')");
      }
      cache_manager::clearCache();
    } else if (!strcmp(argv[2], "search")) {
      if (argc == 7 && !strcmp(argv[3], "matrix")) {
        cache_manager::searchInMatrixCache(argv[4], argv[5], argv[6]);
      } else if (argc == 6) {
        if (!strcmp(argv[3], "image")) {
          cache_manager::searchInImageCache(argv[4], argv[5]);
        } else if (!strcmp(argv[3], "hash")) {
          cache_manager::searchInHashCache(argv[4], argv[5]);
        } else {
          throw exceptions::CacheException("the category's name is not valid "
                                           "(should be matrix, image or hash)");
        }
      }
    } else {
      throw exceptions::CacheException(
          "the function's name is not valid (it must be clear or search)");
    }
  } else {
    throw exceptions::CacheException("the category's name is not valid (it "
                                     "must be matrix, hash, image or cache)");
  }
}

int main(int argc, char **argv) {

  try {
    ex3Format(argc, argv);

    std::ifstream in(paths::getDefaultResultFilePath());
    if (in.good()) {
      std::filesystem::remove(paths::getDefaultResultFilePath());
    }
    in.close();

  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "unkown error has been accured" << std::endl;
  }
}