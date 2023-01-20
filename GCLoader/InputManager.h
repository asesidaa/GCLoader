#pragma once

#include <Windows.h>

#include "Settings.h"

class InputManager {
private:
    Settings settings_;

public:
    void setSettings(const Settings& settings) {
        settings_ = settings;
    }

    DWORD GetInput() const;
};

inline InputManager manager;