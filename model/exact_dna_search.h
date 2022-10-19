#pragma once

#include <string>
#include <vector>

constexpr int p = 10; 
constexpr int q = 256; 

class Hash {
public:
    Hash();
};

class RabinKarp {
public:
    RabinKarp(std::string text, std::string pattern);
    ~RabinKarp() = default;
    const std::vector<int>& GetResult();
private:
    std::vector<int> position_;
    std::string text_;
    std::string pattern_;
    int patternLength_;
    int textLength_;
    int maxP_{1};

    int GetHash(const std::string& str);
    int GetSlidingHash(const std::string& str, int preHash, int index);
    void InitializingArguments();
};