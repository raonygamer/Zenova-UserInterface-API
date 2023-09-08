#pragma once
#include "minecraft/container/Container.h"
#include "mod/ui/ContainerEnums.h"
#include "SlotData.h"
#include "minecraft/item/ItemStack.h"
#include "minecraft/container/ContainerItemStack.h"

class ContainerModel : public ContainerContentChangeListener {
public:
    std::string mContainerStringName;
    const ContainerEnumName mContainerEnumName;
    std::vector<ContainerItemStack> mItems;
    std::vector<ItemInstance> mItemInstances;
    std::vector<std::function<void(int, const ItemStack&, const ItemStack&)>> mOnContainerChangedCallbacks;
    std::function<void(int, const ItemStack&, const ItemStack&)> mPlayerNotificationCallbacks;
    ContainerCategory mContainerCategory;
    std::vector<SlotData, std::allocator<SlotData>> mItemSource;

    ContainerModel(ContainerEnumName, int, ContainerCategory);
    virtual void containerContentChanged(int);
    virtual ~ContainerModel();
    virtual void postInit(void);
    virtual void releaseResources(void);
    virtual int getContainerSize(void) const;
    virtual int getFilteredContainerSize(void) const;
    virtual void tick(int);
    virtual const ContainerItemStack& getItem(int) const;
    virtual const std::vector<ContainerItemStack>& getItems(void) const;
    virtual const std::vector<ItemInstance>& getItemInstances(void);
    virtual void setItem(int, const ContainerItemStack&);
    virtual bool isValid(void);
    virtual bool isItemFiltered(const ContainerItemStack&) const;
    virtual bool isExpanableItemFiltered(int) const;
    virtual ContainerExpandStatus getItemExpandStatus(int) const;
    virtual const std::string& getItemGroupName(int) const;
    virtual void switchItemExpando(int);
    virtual int _getContainerOffset(void) const;
    virtual void _onItemChanged(int, const ItemStack&, const ItemStack&);
    std::string getContainerStringName() const {
        return mContainerStringName;
    }
    ContainerEnumName getContainerEnumName() const {
        return mContainerEnumName;
    }
    void registerOnContainerChangedCallback(std::function<void(int, ItemStack const&, ItemStack const&)>);
};