#pragma once
#include "ContainerManagerController.hpp"
#include "../manager_models/LevelContainerManagerModel.hpp"

class LevelContainerManagerController : public ContainerManagerController {
public:
	LevelContainerManagerController(std::weak_ptr<LevelContainerManagerModel> model);
	virtual ~LevelContainerManagerController();
	virtual bool isContainerValid(float);
};