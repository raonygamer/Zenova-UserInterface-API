#pragma once
#include <string>

struct AutoPlaceItem {
    std::string collection;
    bool stopWhenPlaced;
public:
    AutoPlaceItem(const std::string& c, bool s) : collection(c), stopWhenPlaced(s) {};
};