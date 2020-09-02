# Assignment Three - Cache Manager
### Ori Dabush - 212945760
### Yorai Roth Hazan - 213251861
* * *
## Solid:
* Single Responsibility principle - each file and class has is own job and responsibility.
  * cache_manager is solving the problems. (each function deal with anothe problem)
  * Cache is storing the results.
  * mat_parser is parsing matrix to strings and opposite way.
  * main is getting the variables and call the cache manager.
* Open/closed principle -
  * we cant change the functions or they will not work.
  * we can use cache manger and cache for other problems and extend them.
* Liskov substitution principle - we did not use inheritance or implemention. (no interface or SuperClass)
* Interface segregation principle - we did not use inheritance or implemention. (no interface or SuperClass)
* Dependency Inversion principle - we did not use inheritance or implemention. (no interface or SuperClass)
### The last three are used to make our code more open to extentions but we did not need them in this assignment. (we used them in an empty way)
* * *
## Design:
### In this assignment we created:
* cache_manager.cpp + cache_manager.h - solving the three problems that u gave us using Cache.
* Cache.cpp + Cache.h - Cache class holding the results.
* mat_parser.cpp + mat_parser.h - parsing Matrix to strings and opposite way.
* exceptions.cpp + exceptions.h - added a cache exception. (not new)
* crc32.c + crc32.h - given files.
* main.cpp - getting the variables and call the cache manager.
* * *
## cache_manager (namespace) is doing the following functions:
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
* tested the matrix add and multiply with a couple of matrices.
* tested the image with lena and more images that we created last excersie.
* the hash worked in our cache. (it worked)
* * *
