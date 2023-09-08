#pragma once
#include "ContainerModel.h"
#include "Container.h"
#include "minecraft/block/Block.h"
#include "minecraft/actor/ActorUniqueID.h"

class LevelContainerModel : public ContainerModel {
public:
    Player& mPlayer;
    bool mPlayerClientSide;
    BlockPos mBlockPos;
    BlockActorType mBlockEntityType;
    ActorUniqueID mEntityUniqueId;

    LevelContainerModel(ContainerEnumName, int, Player&, BlockActorType, const BlockPos&, ContainerCategory);
    LevelContainerModel(ContainerEnumName, int, Player&, ActorUniqueID, ContainerCategory);
    virtual void containerContentChanged(int);
    virtual ~LevelContainerModel();
    virtual void postInit(void);
    virtual void releaseResources(void);
    virtual bool isValid(void);
    virtual int _getContainerOffset(void) const;
    virtual void _onItemChanged(int, const ItemStack&, const ItemStack&);
    const BlockPos& getBlockPos() const {
        return mBlockPos;
    }
};