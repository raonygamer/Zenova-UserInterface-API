#pragma once
#include "ScreenControllerProxy.hpp"

class ContainerScreenControllerProxyCallbacks;

class ContainerScreenControllerProxy : public ScreenControllerProxy {
protected:
    char filler[0x90 - sizeof(ScreenControllerProxy)];
public:
    ContainerScreenControllerProxy(ContainerScreenControllerProxyCallbacks&&);
    virtual ~ContainerScreenControllerProxy();
};