#pragma once
#include "Container.h"
#include "ContainerModel.h"

class PlayerUIContainerModelBase : public ContainerModel {
protected:
    Player& mPlayer;

public:
    PlayerUIContainerModelBase(ContainerEnumName enumName, Player& player, int s, ContainerCategory cat) : 
        ContainerModel(enumName, s, cat),
        mPlayer(player)
    {}
    virtual void containerContentChanged(int);
    virtual ~PlayerUIContainerModelBase(void);
    virtual void postInit(void);
    virtual void releaseResources(void);
    virtual bool isValid(void);
    virtual int _getContainerOffset(void) const;
    virtual void _onItemChanged(int, const ItemStack&, const ItemStack&);
    virtual Container& _getContainer(void) const;
};