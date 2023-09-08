#pragma once
#include <memory>
#include "minecraft/client/IClientInstance.h"
#include "minecraft/actor/LocalPlayer.h"

class IMinecraftGame;
class IClientInstance;
class SceneStack;
class SceneFactory;

class MinecraftScreenModel : std::enable_shared_from_this<MinecraftScreenModel> {
public:
    char filler0[0x10 - sizeof(void*)];
    IClientInstance& mClientInstance;
    char filler1[0x68];

public:
    MinecraftScreenModel(class IMinecraftGame&, class IClientInstance&, class SceneStack&, class SceneFactory&);
    virtual ~MinecraftScreenModel();

    IClientInstance& getClientInstance() const {
        return mClientInstance;
    }

    Player& getPlayer() const {
        return getClientInstance().getLocalPlayer();
    }
};