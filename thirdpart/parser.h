#pragma once

#include <string>
#include <vector>

class Parser {
public:
    Parser() = default;
    ~Parser() = default;
    const std::string GetFile(const std::string& filename);
};
