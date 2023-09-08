#pragma once
#include <memory>
#include <functional>
#include <string>
#include "controllers/ScreenController.hpp"
#include "models/ClientInstanceScreenModel.hpp"
#include "minecraft/ui/controllers/ChestScreenController.hpp"
#include "minecraft/ui/controllers/FurnaceScreenController.hpp"
#include "UIScene.h"
#include <typeinfo>
#include "Zenova.h"
#include "minecraft/blockactor/BlockActorType.h"
#include "minecraft/client/IClientInstance.h"
#include "minecraft/client/Options.h"
#include "minecraft/actor/LocalPlayer.h"
#include "ui/custom/dmfurnace/DarkMatterFurnaceScreenController.hpp"
#include "ui/custom/energycondensermk1/EnergyCondenserMK1ScreenController.h"

class BlockPos;
class IMinecraftGame;
class SceneStack {
public:
	void pushScreen(std::shared_ptr<AbstractScene>, bool);
};

class SceneFactory {
private:
	char filler_0[0x10];
	IMinecraftGame& minecraftGame;
	bool isUsingClientSceneStack;
	char filler_1[0x7];
	class IClientInstance& clientInstance;
public:
	//General functions for multiple purpose
	std::shared_ptr<AbstractScene> _createScreen(std::shared_ptr<BaseScreen>);
	std::shared_ptr<UIScene> createUIScene(IMinecraftGame&, class IClientInstance&, std::string const&, std::shared_ptr<ScreenController>);

	//base functions
	SceneStack& getSceneStack() const {
		if (isUsingClientSceneStack || clientInstance.isPrimaryClient()) {
			return clientInstance.getClientSceneStack();
		}
		else {
			return clientInstance.getMainSceneStack();
		}
	}
	IClientInstance& getClientInstance() const {
		return clientInstance;
	}
	InteractionModel getInteractionModel(IClientInstance& client) const {
		return (InteractionModel)(client.getOptions().getUIProfile() == UIProfile::Classic);
	}

	template<typename C = ClientInstanceScreenController, typename... Args>
	std::shared_ptr<UIScene> createScreen(IMinecraftGame& game, class IClientInstance& client, const std::string& name, Args&&... args) {
		auto model = std::make_shared<ClientInstanceScreenModel>(game, client, this->getSceneStack(), *this);
		std::shared_ptr<ScreenController> controller = std::make_shared<C>(model, std::forward<Args>(args)...);
		return this->createUIScene(game, client, name, controller);
	}

	static std::shared_ptr<AbstractScene> createDMFurnaceScreen(Player& player, const BlockPos& pos) {
		auto& clientInstance = static_cast<LocalPlayer&>(player).getClientInstance();
		auto& sceneFactory = clientInstance.getSceneFactory();
		auto uiScene = sceneFactory.createScreen<DarkMatterFurnaceScreenController>(
			sceneFactory.minecraftGame,
			clientInstance,
			"furnace.furnace_screen",
			pos,
			sceneFactory.getInteractionModel(clientInstance)
		);
		return sceneFactory._createScreen(uiScene);
	}

	static std::shared_ptr<AbstractScene> createCondenserMK1Screen(Player& player, const BlockPos& pos) {
		auto& clientInstance = static_cast<LocalPlayer&>(player).getClientInstance();
		auto& sceneFactory = clientInstance.getSceneFactory();
		auto uiScene = sceneFactory.createScreen<EnergyCondenserMK1ScreenController>(
			sceneFactory.minecraftGame,
			clientInstance,
			"energy_condenser.energy_condenser_screen",
			pos,
			sceneFactory.getInteractionModel(clientInstance)
		);
		return sceneFactory._createScreen(uiScene);
	}

	static void _ServerPlayer_openTestScreen(Player& player, const BlockPos& pos) {
		player.openContainer(pos);
	}

	static void openDMFurnaceScreen(Player& player, const BlockPos& pos) {
		if (!player.canOpenContainerScreen()) return;
		if (player.isLocalPlayer()) {
			SceneFactory& factory = static_cast<LocalPlayer&>(player).clientInstance.getSceneFactory();
			auto screen  = createDMFurnaceScreen(player, pos);
			factory.getSceneStack().pushScreen(screen, false);
		}
		else {
			_ServerPlayer_openTestScreen(player, pos);
		}
	}

	static void openCondenserMK1Screen(Player& player, const BlockPos& pos) {
		if (!player.canOpenContainerScreen()) return;
		if (player.isLocalPlayer()) {
			SceneFactory& factory = static_cast<LocalPlayer&>(player).clientInstance.getSceneFactory();
			auto screen = createCondenserMK1Screen(player, pos);
			factory.getSceneStack().pushScreen(screen, false);
		}
		else {
			_ServerPlayer_openTestScreen(player, pos);
		}
	}

	std::shared_ptr<UIScene> createChestScreen(SceneFactory& factory, IMinecraftGame& game, class IClientInstance& client, const std::string& name, const BlockPos& p, InteractionModel& im, BlockActorType&& type);
};