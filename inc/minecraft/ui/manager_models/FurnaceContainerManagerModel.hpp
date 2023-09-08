#pragma once
#include "ContainerManagerModel.hpp"
#include "ui/ContainerEnumName.h"

class FurnaceContainerManagerModel : public ContainerManagerModel {
    BlockPos mBlockPos;
    int mLastTickCount;
    int mLastLitTime;
    int mLastLitDuration;
    int mLastStoredXP;
    int mLastInputId;
    int mLastInputAux;
    std::string mLastOutputName;
    int mLastResultDisplayId;
    const BlockActorType mBlockActorType;
    const ContainerEnumName mIngredientContainerName;
    const Util::HashString mRecipeTag;

public:
	FurnaceContainerManagerModel(ContainerID, Player&, const BlockPos&);
	FurnaceContainerManagerModel(const Util::HashString&, ContainerType, BlockActorType, ContainerID, Player&, const BlockPos&);
    virtual ~FurnaceContainerManagerModel() = default;
    virtual void init(void);
    virtual std::vector<ContainerItemStack> getItems(void);
    virtual void setSlot(int, const ContainerItemStack&, bool);
    virtual const ContainerItemStack getSlot(int);
    virtual void setData(int, int);
    virtual void broadcastChanges(void);
};