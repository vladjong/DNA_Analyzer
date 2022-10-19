#include "exact_dna_search.h"
#include <cmath>
#include <iostream>

const std::vector<int>& RabinKarp::GetResult(const std::string& text, const std::string& pattern) {
    SetText(text, pattern);
    InitializingArguments();
    int patternHash = GetHash(pattern_);
    int textHash = GetHash(text_.substr(0, patternLength_));
    for (int i = 0; i < (textLength_ - patternLength_ + 1); i++) {
        if (patternHash == textHash && text_.substr(i, patternLength_) == pattern_) {
            position_.push_back(i);
        }
        if (i < textLength_ - patternLength_) {
            textHash = GetSlidingHash(text_, textHash, i);
        }
    }
    return position_;
}

void RabinKarp::SetText(const std::string& text, const std::string& pattern) {
    text_ = text;
    pattern_ = pattern;
}

int RabinKarp::GetHash(const std::string& str) {
    int hash = 0;
    int m = str.length();
    for (int i = 0; i < m; i++) {
        hash = (p * hash + int(str[i])) % q;
    }
    return hash;
}

int RabinKarp::GetSlidingHash(const std::string& str, int preHash, int index) {
    preHash = ((preHash - int(text_[index]) * maxP_) * p + int(text_[index + patternLength_])) % q;
    if (preHash < 0) {
        preHash += q;
    }
    return preHash;
}

void RabinKarp::InitializingArguments() {
    textLength_ = text_.length();
    patternLength_ = pattern_.length();
    maxP_ = int(pow(p, patternLength_ - 1)) % q;
}
