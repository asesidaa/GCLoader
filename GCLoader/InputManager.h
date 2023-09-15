#pragma once

#include <Windows.h>

#include "Settings.h"
#pragma comment(lib, "winmm.lib")
class InputManager {
private:
    Settings settings_;

public:
    void setSettings(const Settings& settings) {
        settings_ = settings;
    }

    DWORD GetInput() const;
private:
    DWORD GetKeyboardInput() const;
    DWORD GetJoyInput() const;
};

inline InputManager manager;