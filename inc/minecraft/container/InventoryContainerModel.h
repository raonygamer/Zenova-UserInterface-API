#pragma once
#include "Container.h"
#include "ContainerModel.h"

class InventoryContainerModel : public ContainerModel {
protected:
    Player& mPlayer;

public:
    InventoryContainerModel(ContainerEnumName enumName, int s, Player& player) : 
        ContainerModel(enumName, s, ContainerCategory::PlayerInventory),
        mPlayer(player) {}
    virtual void containerContentChanged(int);
    virtual ~InventoryContainerModel(void);
    virtual void postInit(void);
    virtual void releaseResources(void);
    virtual bool isValid(void);
    virtual int _getContainerOffset(void) const;
    virtual void _onItemChanged(int, const ItemStack&, const ItemStack&);
    virtual Container& _getContainer(void) const;
};