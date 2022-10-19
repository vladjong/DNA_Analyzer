#include "model/exact_dna_search.h"
#include <iostream>

int main() {
    std::string text = "Hello my name Vlad! I am junior backend developer Vlad";
    std::string pattern = "Vlad";
    RabinKarp r(text, pattern);
    auto pos = r.GetResult();
    for (auto &i : pos) {
        std::cout << i << "\n";
    }
}