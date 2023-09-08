#pragma once

enum class ScreenControllerProxyType {
    Default = 0,
    CraftingScreenControllerProxy = 1,
    ContainerScreenControllerProxy = 2,
    FurnaceScreenControllerProxy = 3
};

class ScreenControllerProxy {
public:
    ScreenControllerProxyType mScreenControllerProxyType;
    ScreenControllerProxy(ScreenControllerProxyType);
    virtual ~ScreenControllerProxy();
};