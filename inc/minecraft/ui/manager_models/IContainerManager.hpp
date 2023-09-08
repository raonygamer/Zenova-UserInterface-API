#pragma once
#include <vector>
#include "minecraft/container/ContainerItemStack.h"

enum class ContainerID : signed char;
enum class ContainerType : signed char;

class IContainerManager {
public:
    IContainerManager() {};
    virtual ~IContainerManager() {};
    virtual ContainerID getContainerId(void) const = 0;
    virtual void setContainerId(ContainerID) = 0;
    virtual ContainerType getContainerType(void) const = 0;
    virtual void setContainerType(ContainerType) = 0;
    virtual std::vector<ContainerItemStack> getItems(void) = 0;
    virtual void setSlot(int, const ContainerItemStack&, bool) = 0;
    virtual const ContainerItemStack getSlot(int) = 0;
    virtual void setData(int, int) = 0;
    virtual void broadcastChanges(void) = 0;
};