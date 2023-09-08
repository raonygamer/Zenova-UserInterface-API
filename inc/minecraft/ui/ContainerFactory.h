#pragma once
#include "../container/Container.h"
#include "../container/ContainerController.h"
#include "manager_models/ContainerManagerModel.hpp"

class ContainerFactory {
public:
	template<typename T, typename... Args>
	static std::shared_ptr<T> createContainerManagerModel(ContainerID id, Player& player, Args&&... args) {
		auto managerModel = std::make_shared<T>(id, player, std::forward<Args>(args)...);
		ContainerFactory::_setPlayerContainerManager(player, managerModel);
		return managerModel;
	}

	static void _setPlayerContainerManager(Player& player, std::shared_ptr<IContainerManager> iManager);
	static std::shared_ptr<IContainerManager> _getPlayerContainerManager(Player& player);
	static std::shared_ptr<ContainerController> createController(std::weak_ptr<ContainerModel>);
};