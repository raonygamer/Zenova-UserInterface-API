#pragma once
#include "MinecraftScreenModel.hpp"

class ClientInstanceScreenModel : public MinecraftScreenModel {
protected:
    char filler[0xE0 - sizeof(MinecraftScreenModel)];
public:
    ClientInstanceScreenModel(class IMinecraftGame&, class IClientInstance&, class SceneStack&, class SceneFactory&);
    virtual ~ClientInstanceScreenModel();
};