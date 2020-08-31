# Assignment Three - Cache Manager
## Ori Dabush - 212945760
## Yorai Roth Hazan - 213251861
* * *
### In this assignment we created:
* cache_manager.cpp + cache_manager.h - solving the three problems that u gave us using Cache.
* Cache.cpp + Cache.h - Cache class holding the results.
* mat_parser.cpp + mat_parser.h - parsing Mat to strings and opposite way.
* exceptions.cpp + exceptions.h - added a cache exception. (not new)
* crc32.c + crc32.h - given files.
* * *
##  cache_manager (namespace) is doing the following functions:
* The following functions are doing their job using Cache
  * addMatrices - add the matrices.
  * multMatrices - multiply the matrices.
  * rotateImage - rotate the given image.
  * convertImageToGrayscale - convert image to grayscale.
  * clearCache - clearing the cache.
  * searchInMatrixCache - search matrix result in cache.
  * searchInImageCache - search image result in cache.
  * searchInHashCache - search hash result in cache.
* void hash - convert file to hash and write the hash in the output file.
* uint32_t hash - convert file to hash and return the hash.
* calculateFileCRC32 - private function that use crc32.cpp to calculate a file to hashcode
* A couple of private functions that we used to solve the big functions.
* * *
## Cache (class)
* Has a fileName member that save the path to the txt file of all the results
* Has a numOfArgs that has the amount of arguments that the Cache should get in order to get the result.
### is doing the following functions:
* constructor
* save - save result in the cache.
* search - search for the result in the cache.
* clear - clear the cache. (deletes all)
* A couple of private functions that we used to solve the big functions.
* * *
## mat_parser (namespace) is doing the following functions:
* matToText - convert a Matrix to a vector of strings.
* textToMat - convert a vector of strings to a Mat.
* deleteSpaces - delete spaces in a string.
* * *
## We added to exceptions files (h + cpp) a CacheException to deal with exceptions in cache.
* * *
## Tests
* * *
