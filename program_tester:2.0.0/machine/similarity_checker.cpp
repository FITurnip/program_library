#include "../header/similarity_checker.h"

size_t max(size_t &a, size_t &b) {
    if(a > b) return a;
    else return b;
}

size_t min(size_t &a, size_t &b) {
    if(a < b) return a;
    else return b;
}

void SimilarityChecker::checkSimilarity(std::vector<std::string> &A, std::vector<std::string> &B) {
    unsigned long itr = 0;
    size_t lenA = A.size(), lenB = B.size();
    size_t maxLen = max(lenA, lenB), minLen = min(lenA, lenB);

    for(unsigned long & i = itr; i < minLen; i++) result[i] = (A[i] == B[i]);
    result[itr] = !((itr < lenA || itr < lenB));
}

// #include <iostream>
// using namespace std;
// int main() {
//     int a = 100;
//     int &b = a;
//     cout << b << endl << &b << endl;
//     return 0;
// }