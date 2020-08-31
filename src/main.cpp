#include "cache_manager.h"

#include <iostream>
#include <string.h>

// ex3.out matrix (add|multiply) <input_file_m1> <input_file_m2> <output_file>
// ex3.out image (rotate|convert) <input_file> <output_file>
// ex3.out hash <algorithm> <input_file> <output_file>
// ex3.out cache (clear|search)

void ex3Format(int argc, char **argv) {
  if (!strcmp(argv[1], "matrix")) {
    if (argc != 6) {
      // error
    }
    if (!strcmp(argv[2], "add")) {
      cache_manager::addMatrices(argv[3], argv[4], argv[5]);
    } else if (!strcmp(argv[2], "multiply")) {
      cache_manager::multMatrices(argv[3], argv[4], argv[5]);
    } else {
      // error
    }

  } else if (!strcmp(argv[1], "image")) {
    if (argc != 5) {
      // error
    }
    if (!strcmp(argv[2], "rotate")) {
      cache_manager::rotateImage(argv[3], argv[4]);
    } else if (!strcmp(argv[2], "convert")) {
      cache_manager::convertImageToGrayscale(argv[3], argv[4]);
    } else {
      // error
    }

  } else if (!strcmp(argv[1], "hash")) {
    if (argc != 5) {
      // error
    }
    if (!strcmp(argv[2], "crc32")) {
      cache_manager::hash(argv[3], argv[4]);
    } else {
      // error
    }

  } else if (!strcmp(argv[1], "cache")) {
    if (!strcmp(argv[2], "clear")) {
      if (argc != 3) {
        // error
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
          // error
        }
      }
    } else {
      // error
    }
  } else {
    // error
  }
}

int main(int argc, char **argv) {
  try {
    ex3Format(argc, argv);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "unkown error has been accured" << std::endl;
  }
}