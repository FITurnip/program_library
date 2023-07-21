#include <vector>
#include <string>

class SimilarityChecker {
    private:
        std::vector<bool> result;
    public:
        void checkSimilarity(std::vector<std::string> &, std::vector<std::string> &);
};