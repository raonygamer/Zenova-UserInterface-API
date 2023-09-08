#pragma once
#include "../../container/RandomizableBlockActorFillingContainer.h"
#include "../../actor/Actor.h"

class ChestBlockActor : public RandomizableBlockActorFillingContainer {
public:
    static const int ITEMS_SIZE = 27;
protected:
    float mSpeed;
    bool mIsGlobalChest;
    bool mUsesLegacyBlockDetection;
    float mObstructionHeight;
    float mOpenness;
    float mOldOpenness;
    bool mIsOpen;
    int mTickInterval;
    bool mPairLead : 1;
    bool mPairingChanged : 1;
    bool mAlongX : 1;
    bool mDeferredPairLoad : 1;
    bool mConverted : 1;
    int mDeferredPairX;
    int mDeferredPairZ;
    ChestBlockActor* mLargeChestPaired;
    BlockPos mLargeChestPairedPosition;
    bool mIsTrappedChest;
    bool mIsFindable;
    std::unordered_set<ActorUniqueID> mOpenedByIds;
    bool mNotifyPlayersOnChange;

public:
    ChestBlockActor(BlockActorType, const std::string&, BlockActorRendererId, const BlockPos&, bool);
    virtual ~ChestBlockActor();

    //virtual functions
    virtual void load(Level&, const CompoundTag&, DataLoadHelper&);
    virtual bool save(CompoundTag&) const;
    virtual bool saveItemInstanceData(CompoundTag&);
    virtual void tick(BlockSource&);
    virtual void filler0() {};
    virtual void onChanged(BlockSource&);
    virtual void filler1() {};
    virtual void filler2() {};
    virtual Unique<Packet> getUpdatePacket(BlockSource&);
    virtual void onPlace(BlockSource&);
    virtual void filler3() {};
    virtual void onRemoved(BlockSource&);
    virtual void triggerEvent(int, int);
    virtual void clearCache();
    virtual void filler4() {};
    virtual void filler5() {};
    virtual BlockActor* getCrackEntity(BlockSource&, const BlockPos&);
    virtual void getDebugText(std::vector<std::string>&, const BlockPos&);
    virtual void filler6() {};
    virtual void filler7() {};
    virtual std::string getName() const;
    virtual void filler8() {};
    virtual void filler9() {};
    virtual Container* getContainer();
    virtual void filler10() {};
    virtual void setItem(int, const ItemStack&);
    virtual const ItemStack& getItem(int) const;
    virtual void loadItems(const CompoundTag&, Level&);
    virtual bool saveItems(CompoundTag&) const;
    virtual void playOpenSound(BlockSource&);
    virtual void playCloseSound(BlockSource&);
    virtual bool _canOpenThis(BlockSource&);
    virtual AABB getObstructionAABB() const;
    virtual bool _detectEntityObstruction(BlockSource&) const;
};