#include "parser.h"

#include <fstream>
#include <string>

const std::string Parser::GetFile(const std::string& filename) {
    std::string line;
    std::string result;
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::invalid_argument("Error: file don't exist");
    }
    while (getline(in, line)) {
        result += line;
    }
    return result;
}