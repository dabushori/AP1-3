#include <string>

namespace cache_manager {
void addMatrices(const std::string &inputfile1, const std::string &inputfile2,
                 const std::string &outputfile);
void multiplyMatrices(const std::string &inputfile1,
                      const std::string &inputfile2,
                      const std::string &outputfile);
void rotateImage(const std::string &inputfile, const std::string &outputfile);
void convertImage(const std::string &inputfile, const std::string &outputfile);
void hash(const std::string &algorithm, const std::string &inputfile,
          const std::string &outputfile);
void clearCache();
void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile1, const std::string &inputfile2,
                   const std::string &outputfile);
void searchInCache(const std::string &searchedFunction,
                   const std::string &inputfile, const std::string &outputfile);
} // namespace cache_manager

// ex3.out matrix (add|multiply) <input_file_m1> <input_file_m2> <output_file>
// ex3.out image (rotate|convert) <input_file> <output_file>
// ex3.out hash <algorithm> <input_file> <output_file>
// ex3.out cache (clear|search)