#pragma once
#include <string>

class SlotData {
    //static SlotData UNKNOWN_LOCATION;
    std::string mCollectionName;
    int mCollectionIndex;
public:
    SlotData(void) {};
    SlotData(std::string&& collectionName, int collectionIndex) :
        mCollectionIndex(collectionIndex), mCollectionName(std::move(collectionName)) {};

    SlotData(const std::string& collectionName, int collectionIndex) :
        mCollectionIndex(collectionIndex), mCollectionName(collectionName) {};

    void set(const std::string& name, int index) {
        mCollectionName = name;
        mCollectionIndex = index;
    }

    void clear(void) {
        mCollectionIndex = 0;
    }

    bool isActive(void) const {
        return (
            mCollectionName != "" &&
            mCollectionIndex >= 0
            );
    }

    bool operator==(const SlotData& data) const {
        return (
            mCollectionName == data.mCollectionName &&
            mCollectionIndex == data.mCollectionIndex
            );
    }
};