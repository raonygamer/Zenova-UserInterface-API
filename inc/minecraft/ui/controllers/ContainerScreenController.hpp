#pragma once
#include "ClientInstanceScreenController.hpp"
#include "minecraft/container/ContainerItemStack.h"
#include "minecraft/item/AutoPlaceItem.h"

enum class InteractionModel;
class ContainerManagerController;

class ContainerScreenController : public ClientInstanceScreenController {
public:
    char filler[0xA20 - 0x40 - sizeof(ClientInstanceScreenController)];
    std::unordered_map<std::string, std::vector<std::string>> mCoalesceOrder;
    std::unordered_map<std::string, std::vector<AutoPlaceItem>> mAutoPlaceOrder;
    char filler2[0x8];
    std::shared_ptr<ContainerManagerController> mManagerController;
    char filler1[0x8];
public:
    ContainerScreenController(std::shared_ptr<ClientInstanceScreenModel>, InteractionModel);
    virtual ~ContainerScreenController();
    virtual ui::DirtyFlag tick();
    virtual void onOpen();
    virtual void onLeave();
    virtual void handleGameEventNotification(ui::GameEventNotification);
    virtual void setAssociatedBlockPos(const BlockPos&);
	virtual void setAssociatedEntityUniqueID(ActorUniqueID);
    virtual void setViewCommand(ScreenViewCommand&);
    virtual void addStaticScreenVars(Json::Value&);
    virtual bool _isStillValid();
    virtual std::string _getButtonADescription();
    virtual std::string _getButtonXDescription();
    virtual std::string _getButtonYDescription();
    virtual ContainerItemStack& _handlePlaceAll(std::string const&,int);
    virtual ContainerItemStack& _handlePlaceOne(std::string const&,int);
    virtual ContainerItemStack& _handleSelectSlot(std::string const&,int);
    virtual std::string _getSelectedSlotInfo(void);
    virtual ContainerItemStack& _getItemStack(std::string const&,int);
    virtual ContainerItemStack& _getVisualItemStack(std::string const&,int);
    virtual void _onContainerSlotHovered(std::string const&,int);
    virtual void _onContainerSlotSelected(std::string const&,int);
    virtual void _onContainerSlotPressed(std::string const&,int);
    virtual bool _shouldSwap(std::string const&,int,std::string const&,int);
    virtual const std::string& _getCollectionName(UIPropertyBag *);
    virtual bool _canSplit(std::string const&,int);
    virtual void _sendFlyingItem(ContainerItemStack const&,std::string const&,int,std::string const&,int);
    virtual void _registerCoalesceOrder();
    virtual void _registerAutoPlaceOrder();

    template<typename C, typename M, typename... Args>
    std::shared_ptr<C> createContainerManagerController(const BlockPos& pos, std::function<std::shared_ptr<M>()> modelCtor, Args&&... args) {
        Player& player = this->getScreenModel().getPlayer();
        auto model = modelCtor();
        auto controller = std::make_shared<C>(model, std::forward<Args>(args)...);
        this->mManagerController = controller;
        this->mManagerController.get()->registerContainerCallbacks(model);
        return controller;
    }
};
static_assert(offsetof(ContainerScreenController, mManagerController) == 0xa68, "mManagerController's offset != 0xa68");
static_assert(offsetof(ContainerScreenController, mCoalesceOrder) == 0x9e0, "mCoalesceOrder's offset != 0x9e0");
static_assert(offsetof(ContainerScreenController, mAutoPlaceOrder) == 0xa20, "mAutoPlaceOrder's offset != 0xa20");