#pragma once
#include "ContainerScreenController.hpp"

class FurnaceScreenController : public ContainerScreenController {
	char filler[0xA98 - sizeof(ContainerScreenController)];
public:
	FurnaceScreenController(std::shared_ptr<ClientInstanceScreenModel>, const BlockPos&, InteractionModel, const Util::HashString&);
	virtual ~FurnaceScreenController();
};