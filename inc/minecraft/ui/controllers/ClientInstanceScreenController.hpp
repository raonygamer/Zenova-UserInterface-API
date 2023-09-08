#pragma once
#include "MinecraftScreenController.hpp"
#include "../models/ClientInstanceScreenModel.hpp"

class ClientInstanceScreenController : public MinecraftScreenController {
public:
    char filler[0x680 - sizeof(MinecraftScreenController)];
public:
    ClientInstanceScreenController(std::shared_ptr<ClientInstanceScreenModel>);
    virtual ~ClientInstanceScreenController();
};