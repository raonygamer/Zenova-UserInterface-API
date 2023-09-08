#pragma once
#include <memory>
#include "minecraft/block/Block.h"
#include "minecraft/client/IClientInstance.h"
#include "../manager_models/ContainerManagerModel.hpp"
#include "../controllers/BlockContainerScreenController.hpp"
#include "../ContainerFactory.h"
#include "minecraft/item/AutoPlaceResult.h"

class SlotData;
class SelectedSlotInfo;

class ContainerManagerController : std::enable_shared_from_this<ContainerManagerController> {
public:
    char filler0[0x18 - sizeof(void*)];
    std::unordered_map<std::string, std::shared_ptr<ContainerController>> mContainerControllers;
    char filler[0x20];
public:
    ContainerManagerController(std::weak_ptr<ContainerManagerModel>);
    virtual ~ContainerManagerController();
    virtual ContainerItemStack& getTakeableItemStack(SlotData const&);
    virtual ContainerItemStack& handleTakeAmount(SlotData const&,int,SlotData const&);
    virtual ContainerItemStack& handleTakeAll(SlotData const&,SlotData const&);
    virtual ContainerItemStack& handlePlaceAll(SelectedSlotInfo const&,SlotData const&);
    virtual ContainerItemStack& handleTakeHalf(SlotData const&,SlotData const&);
    virtual ContainerItemStack& handlePlaceOne(SlotData const&,SlotData const&);
    virtual ContainerItemStack& handlePlaceAmount(SlotData const&,int,SlotData const&);
    virtual int handleAutoPlace(SlotData const&,int,std::vector<AutoPlaceItem> const&,std::vector<AutoPlaceResult> &);
    virtual int handleAutoPlaceStack(SlotData const&,ItemTakeType,std::vector<AutoPlaceItem> const&,std::vector<AutoPlaceResult> &);
    virtual void handleSplitSingle(SlotData const&,SlotData const&);
    virtual void handleSplitMultiple(SelectedSlotInfo const&,ItemInstance const&,SlotData const&);
    virtual ContainerItemStack& handleCoalesce(SlotData const&,std::vector<std::string> const&);
    virtual ContainerItemStack& handleSwap(SlotData const&,SlotData const&);
    virtual ContainerItemStack& handleDrop(SlotData const&,ItemTransferAmount);
    virtual ContainerItemStack& handleDestroy(SelectedSlotInfo const&,ItemTransferAmount);
    virtual ContainerItemStack& handleDestroy(SlotData const&,ItemTransferAmount);
    virtual ContainerItemStack& handleConsume(SlotData const&,ItemTransferAmount);
    virtual ContainerItemStack& handleAddToStack(SlotData const&,SlotData const&,ItemTakeType);
    virtual void closeContainers(void);
    virtual ItemStack& getSplitItems(void);
    virtual bool isOutputSlot(std::string const&);
    virtual void _onItemTransferredFrom(ItemInstance const&,SlotData const&);
    virtual void _onItemTransferredTo(ItemInstance const&,SlotData const&);
    virtual void _onItemAcquired(ItemInstance const&,SlotData const&);
    virtual void _onItemPlaced(ItemInstance const&,SlotData const&);

    void registerContainerCallbacks(std::weak_ptr<ContainerManagerModel>);
};
static_assert(offsetof(ContainerManagerController, mContainerControllers) == 0x28, "mContainerControllers's offset != 0x28");