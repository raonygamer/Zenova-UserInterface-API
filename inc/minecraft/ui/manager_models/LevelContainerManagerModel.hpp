#pragma once
#include "ContainerManagerModel.hpp"
#include "../../actor/Actor.h"
#include <string>

class Player;
enum class BlockActorType;

class LevelContainerManagerModel : public ContainerManagerModel {
  private:
    BlockPos mBlockPos;
    ActorUniqueID mEntityUniqueID;
    BlockActorType mBlockActorType;

  public:
    LevelContainerManagerModel(ContainerID id, Player& player, const BlockPos& pos, BlockActorType blockActorType) :
          ContainerManagerModel(id, player),
          mBlockActorType(blockActorType), mBlockPos(pos), mEntityUniqueID({-1})
    {}
    LevelContainerManagerModel(ContainerID id, Player& player, const ActorUniqueID uniqueID) :
        ContainerManagerModel(id, player),
        mBlockActorType(BlockActorType::Undefined), mBlockPos(BlockPos::ZERO), mEntityUniqueID(uniqueID)
    {}
    virtual ~LevelContainerManagerModel();
    virtual std::vector<ContainerItemStack> getItems(void);
    virtual void setSlot(int, const ContainerItemStack &, bool);
    virtual const ContainerItemStack getSlot(int);
    virtual void setData(int, int);
    virtual void broadcastChanges(void);
    virtual void init(void);
    virtual bool isValid(float);

    const BlockPos& getBlockPos() const {
        return mBlockPos;
    }
};