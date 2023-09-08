#pragma once
#include "ScreenController.hpp"
#include "../models/MinecraftScreenModel.hpp"

enum class ScreenExitBehavior;

class MinecraftScreenController : public ScreenController {
public:
    char filler0[0x10];
    std::shared_ptr<MinecraftScreenModel> mScreenModel;
    char filler1[0x668 - (0x10 + 0x8) - sizeof(ScreenController)];
public:
    MinecraftScreenController(std::shared_ptr<MinecraftScreenModel>, ScreenExitBehavior);
    virtual ~MinecraftScreenController();
    virtual ui::DirtyFlag tick();
    virtual void onOpen();
    virtual int tryExit();
    virtual void leaveScreen();
    virtual bool bind(const std::string&, uint32_t, int32_t, const std::string&, uint32_t, const std::string&, UIPropertyBag&);
	virtual bool bind(const std::string&, uint32_t, const std::string&, UIPropertyBag&);
    virtual void onDictationEvent(const std::string&);
    virtual void setSuspendInput(bool);
    virtual bool _isStillValid();
    virtual bool _getGamepadHelperVisible();
    virtual bool _getMixedHelperVisible();
    virtual bool _getKeyboardHelperVisible();
    virtual std::string _getButtonADescription();
    virtual std::string _getButtonBDescription();
    virtual std::string _getButtonXDescription();
    virtual std::string _getButtonYDescription();
    virtual std::string _getButtonKeyboardDescription();

    MinecraftScreenModel& getScreenModel() const {
        return *mScreenModel.get();
    }
};