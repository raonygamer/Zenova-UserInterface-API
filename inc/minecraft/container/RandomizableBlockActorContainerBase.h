#pragma once
#include "../blockactor/BlockActor.h"

class RandomizableBlockActorContainerBase : public BlockActor {
protected:
    std::string mLootTable;
    int mLootTableSeed;

public:
    RandomizableBlockActorContainerBase(BlockActorType, const std::string&, const BlockPos&);

    //virtual functions
    virtual ~RandomizableBlockActorContainerBase();
    virtual void filler0() {};
    virtual void filler1() {};

    //member functions
    void setLootTable(std::string, int);
    void unPackLootTable(Level&, Container&, Actor*);
};