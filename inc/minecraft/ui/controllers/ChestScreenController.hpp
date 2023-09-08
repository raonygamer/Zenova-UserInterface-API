#pragma once
#include "BlockContainerScreenController.hpp"
#include "minecraft/block/ActorBlock.h"

class ChestScreenController : public BlockContainerScreenController {
public:
	ChestScreenController(std::shared_ptr<ClientInstanceScreenModel>, const BlockPos&, InteractionModel, BlockActorType);
	virtual ~ChestScreenController();
	virtual void _registerCoalesceOrder();
	virtual void _registerAutoPlaceOrder();
};