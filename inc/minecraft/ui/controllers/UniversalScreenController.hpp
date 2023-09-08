#pragma once
#include "ChestScreenController.hpp"

class UniversalScreenController : public ChestScreenController {
public:
	UniversalScreenController(std::shared_ptr<ClientInstanceScreenModel> model, const BlockPos& pos, InteractionModel iModel, BlockActorType type) :
		ChestScreenController(model, pos, iModel, type) {}
	virtual ~UniversalScreenController() = default;
};