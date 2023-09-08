#pragma once
#include "IContainerManager.hpp"
#include "../../container/ContainerModel.h"
#include <functional>

class Player;

class ContainerManagerModel : public IContainerManager {
  protected:
    Player& mPlayer;
    std::vector<ContainerItemStack> mLastSlots;
    ContainerID mContainerId;
    ContainerType mContainerType;
    std::function<void(ContainerManagerModel&)> mInformControllerOfDestructionCallback;
    std::unordered_map<std::string, std::shared_ptr<ContainerModel>> mContainers;

  public:
    ContainerManagerModel(ContainerID, Player &);
    virtual ~ContainerManagerModel();
    virtual void init(void);
    virtual ContainerID getContainerId(void) const;
    virtual void setContainerId(ContainerID);
    virtual ContainerType getContainerType(void) const;
    virtual void setContainerType(ContainerType);
    virtual bool isValid(float);
    void registerInformControllerOfDestructionCallback(std::function<void (ContainerManagerModel &)>);
  protected:
    void _addContainer(std::shared_ptr<ContainerModel> model) {
        mContainers[model.get()->getContainerStringName()] = model;
    }
};