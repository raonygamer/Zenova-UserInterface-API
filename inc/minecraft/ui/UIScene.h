#pragma once

enum class InteractionModel {
	_0,
	_1
};

class AbstractScene { };
class BaseScreen : public AbstractScene { };
class UIScene : public BaseScreen { };