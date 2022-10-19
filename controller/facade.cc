#include "facade.h"

Facade::Facade() {
    parser_ = std::make_unique<Parser>();
    rabinKarp_ = std::make_unique<RabinKarp>();
}

const std::vector<int>& Facade::GetExactDNASearch(const std::string& textFile, const std::string& patternFile) {
    auto text = parser_->GetFile(textFile);
    auto pattern = parser_->GetFile(patternFile);
    return rabinKarp_->GetResult(text, pattern);
}