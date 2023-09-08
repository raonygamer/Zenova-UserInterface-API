#pragma once
#include "minecraft/actor/Player.h"
#include "PlayerUIContainerModelBase.h"

class PlayerUIContainerModel : public PlayerUIContainerModelBase {
public:
    PlayerUIContainerModel(ContainerEnumName enumName, Player& player) : PlayerUIContainerModelBase(enumName, player, 9, ContainerCategory::Default) 
    {
    
    }
    virtual ~PlayerUIContainerModel(void);
    virtual int _getContainerOffset(void) const;
};