#pragma once

#include "../ActorBlock.h"
#include "../Material.h"
#include "../../blockactor/vanilla/ChestBlockActor.hpp"

class ChestBlock : public ActorBlock {
public:
    enum ChestType {
        TYPE_BASIC,
        TYPE_TRAP,
        TYPE_ENDER,
        TYPE_IRON
    };

    static const int EVENT_SET_IS_OPEN = 1;
private:
    ChestType mType;

public:
    ChestBlock(const std::string& nameId, int id, ChestType type = ChestType::TYPE_BASIC, MaterialType materialType = MaterialType::Wood);
    virtual BlockLegacy& init();
    virtual const Block& getPlacementBlock(Actor& by, const BlockPos& pos, FacingID face, const Vec3& clickPos, int itemValue) const;
    virtual void setupRedstoneComponent(BlockSource& region, const BlockPos& pos) const;
    virtual void onPlace(BlockSource& region, const BlockPos& pos) const;
    virtual void onRemove(BlockSource& region, const BlockPos& pos) const;
    virtual void onMove(BlockSource& region, const BlockPos& from, const BlockPos& to) const;
    virtual bool detachesOnPistonMove(BlockSource& region, const BlockPos& pos) const;
    virtual bool hasComparatorSignal() const;
    virtual int getComparatorSignal(BlockSource& region, const BlockPos& pos, const Block& block, FacingID dir) const;
    virtual FacingID getMappedFace(FacingID face, const Block& block) const;
    virtual bool use(Player&, const BlockPos&) const;
    virtual bool getSecondPart(BlockSource& region, const BlockPos& pos, BlockPos& out) const;
    virtual bool isInteractiveBlock() const;
    virtual bool isContainerBlock() const;
    virtual bool isSignalSource() const;
    virtual bool shouldConnectToRedstone(BlockSource& region, const BlockPos& pos, int direction) const;
};