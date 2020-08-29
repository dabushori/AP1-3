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