#include "controller/facade.h"
#include <iostream>

int main() {
    Facade f;
    auto result = f.GetExactDNASearch("data/text.txt", "data/pattern.txt");
    for (auto &i : result) {
        std::cout << i << "\n";
    }
}