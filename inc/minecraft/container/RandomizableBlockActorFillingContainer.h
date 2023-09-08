#pragma once
#include "FillingContainer.h"
#include "RandomizableBlockActorContainerBase.h"

class RandomizableBlockActorFillingContainer : public RandomizableBlockActorContainerBase, public FillingContainer {
public:
    RandomizableBlockActorFillingContainer(BlockActorType, const std::string&, const BlockPos&, int, ContainerType);

    //virtual functions
    virtual ~RandomizableBlockActorFillingContainer();
    virtual void filler0() {};
    virtual void filler1() {};
};