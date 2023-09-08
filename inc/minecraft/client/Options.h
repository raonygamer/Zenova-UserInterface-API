#pragma once

enum class UIProfile : int {
	Classic,
	Pocket
};

class Option {
public:
    int getInt() {
        return 0;
    }
};

class Options {
    public:
    char filler0[0xA0];
    Option* uiOption;
    char filler1[0x48];
    UIProfile profile;

    UIProfile getUIProfile() {
        if (uiOption) {
            return (UIProfile)uiOption->getInt();
        } 
        else {
            return profile;
        }
    }
};