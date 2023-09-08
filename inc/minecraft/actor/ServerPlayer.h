#pragma once
#include "Player.h"
#include "minecraft/world/Container.h"

class ServerPlayer : public Player {
	char filler[0x2300];
public:
	ContainerID containerId;
	void openDMFurnace(const BlockPos&);
	void _setContainerManager(std::shared_ptr<IContainerManager>);
};