cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# add the .cpp files of the project
add_executable(ex3 
                bmp/bmp.cpp 
                bmp/bmp_tester.cpp 
                cache/Cache.cpp 
                cache/cache_manager.cpp 
                hash/crc32.cpp 
                exceptions/exceptions.cpp 
                main.cpp 
                matrix/matrix.cpp 
                matrix/mat_parser.cpp)

# add the library
target_link_libraries(ex3 matrix)

# add the folders of the .h files (to be able to include them)
target_include_directories(ex3 PUBLIC
                            ${CMAKE_SOURCE_DIR}/bmp
                            ${CMAKE_SOURCE_DIR}/cache
                            ${CMAKE_SOURCE_DIR}/exceptions
                            ${CMAKE_SOURCE_DIR}/hash
                            ${CMAKE_SOURCE_DIR}/matrix
                            )

# make the cache directory
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/cache)

# include the src directory
target_link_directories(ex3 PUBLIC ${PROJECT_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
