#pragma once
#include <string>

struct AutoPlaceResult {
    std::string collectionName;
    int collectionIndex;
public:
    AutoPlaceResult(const std::string& cN, int cI) : collectionName(cN), collectionIndex(cI) {}
};