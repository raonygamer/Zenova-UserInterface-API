#pragma once
#include "IScreenController.hpp"
class NameRegistry;
class ScreenEvent;
class ScreenViewCommand;
class ScreenControlleProxy;
class PropertyBag {};
class UIPropertyBag : public PropertyBag {};

namespace ui {
	enum GameEventNotification;
	enum ViewRequest;
	enum SceneType {
		Default = 0x1
	};
	enum DirtyFlag;
}

namespace Json {
	class Value;
}

class ScreenController : public IScreenController {
	char filler[0x520 - sizeof(void*)];
public:
	ScreenController(NameRegistry&, bool);
	virtual ~ScreenController();
	virtual ui::DirtyFlag tick();
	virtual ui::ViewRequest handleEvent(ScreenEvent&);
	virtual void onOpen();
	virtual void onTerminate();
	virtual void onInit();
	virtual bool canExit();
	virtual int tryExit();
	virtual bool areControllerTabsEnabled();
	virtual void onCreation();
	virtual void logCreationTime(const std::string&, double, double, unsigned char);
	virtual void onLeave();
	virtual void leaveScreen();
	virtual void handleGameEventNotification(ui::GameEventNotification);
	virtual bool bind(const std::string&, uint32_t, int32_t, const std::string&, uint32_t, const std::string&, UIPropertyBag&);
	virtual bool bind(const std::string&, uint32_t, const std::string&, UIPropertyBag&);
	virtual void handleLicenceChanged();
	virtual void onDictationEvent(const std::string&);
	virtual void setAssociatedBlockPos(const BlockPos&);
	virtual void setAssociatedEntityUniqueID(ActorUniqueID);
	virtual void setSuspendInput(bool);
	virtual float getCallbackInterval();
	virtual void setViewCommand(ScreenViewCommand&);
	virtual void onRender();
	virtual void addStaticScreenVars(Json::Value&);
	virtual std::string getAdditionalScreenInfo();
	virtual std::string getTelemetryOverride();
	virtual void addEventProperties(std::unordered_map<std::string, std::string>&);
	virtual ui::SceneType getSceneType();
	virtual int getScreenVersion();
	virtual bool screenHandlesGamepadMenuButton();
	virtual ScreenControlleProxy& getProxy();
	virtual void onEntered();
	virtual size_t getNameId(const std::string&);
	virtual bool _doesScreenHaveExitBehavior();
};