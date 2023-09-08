#pragma once
#include "Player.h"

class NetworkIdentifier;
class Certificate;
class IClientInstance;
class SceneStack;

namespace mce {
	class UUID {};
}

class LocalPlayer : public Player {
public:
	LocalPlayer(IClientInstance&, Level&, std::string const&, GameType, NetworkIdentifier const&, unsigned char, mce::UUID, std::string const&, std::unique_ptr<Certificate>);

private:
	char filler0[0x1908];
public:
	IClientInstance& clientInstance;
	IClientInstance& getClientInstance() {
		return clientInstance;
	}

	//void openDMFurnace(const BlockPos& pos);
};