#pragma once

#include "Container.h"

class ListTag;
class SemVersion;

class FillingContainer : public Container {
public:
    static const int MAX_INVENTORY_STACK_SIZE = 254;
    static const int LEGACY_INVENTORY_SIZE = 54;
    static const int SURVIVAL_INVENTORY_SIZE = 36;
    static const int HOTBAR_SIZE = 9;
protected:
    std::vector<ItemStack> mItems;
    Player* mPlayer;

public:
    FillingContainer(Player* plr, int itemAmount, ContainerType type) : Container(type), mPlayer(plr) {
        mItems.resize(itemAmount);
    }
    virtual ~FillingContainer();
    bool hasResource(int);
    bool getAndRemoveResource(ItemStack&, bool, bool);
    bool removeResource(int);
    bool removeResource(const ItemStack&);
    int removeResource(const ItemStack&, bool, bool, int);
    void swapSlots(int, int);
    virtual bool add(ItemStack&);
    virtual bool canAdd(const ItemStack&) const;
    void dropSlot(int, bool, bool, bool);
    virtual void dropAll(bool);
    void dropAll(int, int, bool);
    virtual void removeItem(int, int);
    virtual void clearSlot(int);
    virtual int clearInventory(int);
    std::unique_ptr<ListTag> save();
    virtual void load(const ListTag&, const SemVersion&, Level&);
    void replace(std::vector<ItemStack>, int);
    virtual void setItem(int, const ItemStack&);
    virtual const ItemStack& getItem(int) const;
    virtual int getMaxStackSize() const;
    virtual int getContainerSize() const;
    virtual void startOpen(Player&);
    virtual void stopOpen(Player&);
    virtual void doDrop(ItemStack&, bool);
    int getSlotWithItem(const ItemStack&, bool, bool) const;
    virtual int getEmptySlotsCount() const;
    virtual int getItemCount(const ItemDescriptor&);
    int getHotbarSize() const;
protected:
    int _getSlot(int) const;
    int _getSlotWithRemainingSpace(const ItemStack&) const;
    int _getFreeSlot() const;
    int _addResource(const ItemStack&);
    void _release(int);
    void _fixBackwardCompabilityItem(ItemStack&);
    bool _isCreative() const;
    int _getEmptySlotsCount(int, int) const;
    void _trySetInSlot(ItemStack&, const int&, const int&, int&);
    CompoundTag* _tryGetTag(const ListTag&, int);
    bool _setSlotIfValid(CompoundTag*, int&, bool, int, int, int);
};