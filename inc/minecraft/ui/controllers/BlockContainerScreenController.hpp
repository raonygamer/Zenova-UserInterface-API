#pragma once
#include "ContainerScreenController.hpp"

class BlockContainerScreenController : public ContainerScreenController {
public:
    std::weak_ptr<ContainerManagerController> mBlockContainerManagerController;
public:
    BlockContainerScreenController(std::shared_ptr<ClientInstanceScreenModel>, const BlockPos&, InteractionModel);
    BlockContainerScreenController(std::shared_ptr<ClientInstanceScreenModel>, ActorUniqueID, InteractionModel);
    virtual ~BlockContainerScreenController();
    virtual bool _isStillValid();
    virtual void _registerCoalesceOrder();
    virtual void _registerAutoPlaceOrder();
};