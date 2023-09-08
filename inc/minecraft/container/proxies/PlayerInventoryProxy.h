#pragma once
#include "minecraft/container/Container.h"
class Inventory;
class HudContainerManagerModel;
class ListTag;

class PlayerInventoryProxy : public ContainerSizeChangeListener, private ContainerContentChangeListener {
    class SlotData;
private:
    int mSelected;
    ItemStack mInfiniteItem;
    ContainerID mSelectedContainerId;
    Unique<Inventory> mInventory;
    std::vector<ItemStack, std::allocator<ItemStack>> mComplexItems;
    std::weak_ptr<HudContainerManagerModel> mHudContainerManager;

public:
    int getContainerSize(ContainerID) const;
    int getHotbarSize() const;
};