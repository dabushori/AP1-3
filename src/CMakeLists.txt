cmake_minimum_required(VERSION 3.0.0)
project(ex2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(ex3 
                bmp.cpp 
                bmp_tester.cpp 
                Cache.cpp 
                cache_manager.cpp 
                crc32.cpp 
                exceptions.cpp 
                main.cpp 
                matrix.cpp 
                mat_parser.cpp)
target_link_libraries(ex3 matrix)

file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/cache)

# to include the src directory
target_link_directories(ex3 PUBLIC ${PROJECT_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
