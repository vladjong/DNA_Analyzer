#pragma once

#include<memory>

#include "../model/exact_dna_search.h"
#include "../thirdpart/parser.h"

class Facade {
public:
    Facade();
    ~Facade() = default;
    const std::vector<int>& GetExactDNASearch(const std::string& text, const std::string& pattern);
private:
    std::unique_ptr<Parser> parser_;
    std::unique_ptr<RabinKarp> rabinKarp_;
};
