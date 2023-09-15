#pragma once

#include <Windows.h>
#include "keycodes.h"
#include "libs/configor/include/configor/json.hpp"

struct Settings {
    Settings() = default;
    int testModeKeycode = VK_KEY_T;
    
    int p1UpKeycode = VK_KEY_W;
    int p2UpKeycode= VK_KEY_S;
    int p1DownKeycode= VK_KEY_A;
    int p2DownKeycode= VK_KEY_D;
    int p1LeftKeycode= VK_UP;
    int p2LeftKeycode= VK_DOWN;
    int p1RightKeycode= VK_LEFT;
    int p2RightKeycode= VK_RIGHT;

    int p1Button1Keycode = VK_KEY_Q;
    int p2Button1Keycode = VK_CONTROL;

    std::string inputMode = "keyboard";

    int joyIndex = 0;
    int UpButtonCode = 1;
    int DownButtonCode = 4;
    int LeftButtonCode = 8;
    int RightButtonCode = 2;
    int Button1Code = 16;
    int Button2Code = 32;

    CONFIGOR_BIND(configor::json::value, Settings,
        REQUIRED(testModeKeycode),
        REQUIRED( p1UpKeycode),
        REQUIRED( p2UpKeycode),
        REQUIRED( p1DownKeycode),
        REQUIRED( p2DownKeycode),
        REQUIRED( p1LeftKeycode),
        REQUIRED( p2LeftKeycode),
        REQUIRED( p1RightKeycode),
        REQUIRED( p2RightKeycode),
        REQUIRED( p1Button1Keycode),
        REQUIRED( p2Button1Keycode),
        REQUIRED(inputMode),
        REQUIRED(joyIndex),
        REQUIRED(UpButtonCode),
        REQUIRED(DownButtonCode),
        REQUIRED(LeftButtonCode),
        REQUIRED(RightButtonCode),
        REQUIRED(Button1Code),
        REQUIRED(Button2Code)
        )
};

Settings GetFromInput(const std::string& filename);
