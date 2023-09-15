#include "InputManager.h"
#include "keycodes.h"
#include "plog/Log.h"

struct Direction
{
    bool Center;
    bool Up;
    bool Down;
    bool Left;
    bool Right;
};

Direction DetectDirection(unsigned long x, unsigned long y)
{
    // Ranges to detect joystick direction
    const unsigned long CENTER_THRESHOLD = 10 * 1000; // Within 10,000 of center
    const unsigned long AXIS_MAX = 65535;

    unsigned long x_mid = AXIS_MAX / 2;
    unsigned long y_mid = AXIS_MAX / 2;

    if (std::abs(static_cast<long long>(x - x_mid)) < CENTER_THRESHOLD && std::abs(static_cast<long long>(y - y_mid)) <
        CENTER_THRESHOLD)
    {
        return Direction{true};
    }

    bool up = y < (y_mid - CENTER_THRESHOLD);
    bool down = y > (y_mid + CENTER_THRESHOLD);
    bool left = x < (x_mid - CENTER_THRESHOLD);
    bool right = x > (x_mid + CENTER_THRESHOLD);

    return Direction{false, up, down, left, right};
}


DWORD InputManager::GetKeyboardInput() const
{
    DWORD val1 = 0;
    DWORD val2 = 0;
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_I) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 1;
    }
    if (GetAsyncKeyState(VK_KEY_P) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 3;
    }

    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        PLOG_DEBUG << "P2 SERVICE" << std::endl;
        val2 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_1) & 0x8000)
    {
        PLOG_DEBUG << "P1 START" << std::endl;
        val1 |= 1 << 4;
    }

    if (GetAsyncKeyState(VK_KEY_2) & 0x8000)
    {
        PLOG_DEBUG << "P2 START" << std::endl;
        val2 |= 1 << 5;
    }

    if (GetAsyncKeyState(settings_.testModeKeycode) & 0x8000)
    {
        PLOG_DEBUG << "TEST Node 1" << std::endl;
        val1 |= 1 << 6;
    }

    if (GetAsyncKeyState(settings_.p1UpKeycode) & 0x8000)

    {
        PLOG_DEBUG << "P1 UP" << std::endl;
        val1 |= 1 << 8;
    }
    if (GetAsyncKeyState(settings_.p2UpKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P2 UP" << std::endl;
        val2 |= 1 << 9;
    }

    if (GetAsyncKeyState(settings_.p1DownKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P1 DOWN" << std::endl;
        val1 |= 1 << 10;
    }

    if (GetAsyncKeyState(settings_.p2DownKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P2 DOWN" << std::endl;
        val2 |= 1 << 11;
    }

    if (GetAsyncKeyState(settings_.p1LeftKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P1 LEFT" << std::endl;
        val1 |= 1 << 12;
    }

    if (GetAsyncKeyState(settings_.p2LeftKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P2 LEFT" << std::endl;
        val2 |= 1 << 13;
    }

    if (GetAsyncKeyState(settings_.p1RightKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P1 RIGHT" << std::endl;
        val1 |= 1 << 14;
    }

    if (GetAsyncKeyState(settings_.p2RightKeycode) & 0x8000)
    {
        PLOG_DEBUG << "P2 RIGHT" << std::endl;
        val2 |= 1 << 15;
    }

    if (GetAsyncKeyState(settings_.p1Button1Keycode) & 0x8000)
    {
        PLOG_DEBUG << "P1 BUTTON 1" << std::endl;
        val1 |= 1 << 16;
    }

    if (GetAsyncKeyState(settings_.p2Button1Keycode) & 0x8000)
    {
        PLOG_DEBUG << "P2 BUTTON 1" << std::endl;
        val2 |= 1 << 17;
    }

    /*if (GetAsyncKeyState(VK_KEY_S) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 2"<< std::endl;
        val1 |= 1 << 18;
    }

    if (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 2"<< std::endl;
        val2 |= 1 << 19;
    }

    if (GetAsyncKeyState(VK_KEY_D) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 3"<< std::endl;
        val1 |= 1 << 20;
    }

    if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 3"<< std::endl;
        val2 |= 1 << 21;
    }

    if (GetAsyncKeyState(VK_KEY_Z) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 4"<< std::endl;
        val1 |= 1 << 22;
    }

    if (GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 4"<< std::endl;
        val2 |= 1 << 23;
    }

    if (GetAsyncKeyState(VK_KEY_X) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 5"<< std::endl;
        val1 |= 1 << 24;
    }

    if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 5"<< std::endl;
        val2 |= 1 << 25;
    }

    if (GetAsyncKeyState(VK_KEY_C) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 6"<< std::endl;
        val1 |= 1 << 26;
    }
    if (GetAsyncKeyState(VK_DECIMAL) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 6"<< std::endl;
        val2 |= 1 << 27;
    }*/
    DWORD ret = val1 | val2;
    return ret;
}

DWORD InputManager::GetInput() const
{
    if (settings_.inputMode == "joystick")
    {
        return GetJoyInput();
    }

    return GetKeyboardInput();
}

DWORD InputManager::GetJoyInput() const
{
    JOYINFOEX joy;
    joy.dwSize = sizeof(joy);
    joy.dwFlags = JOY_RETURNALL;
    
    DWORD val1 = 0;
    DWORD val2 = 0;

    if (joyGetPosEx(settings_.joyIndex, &joy) == JOYERR_NOERROR)
    {
        const auto [Center, Up, Down, Left, Right] = DetectDirection(joy.dwXpos, joy.dwYpos);
        if (Up)
        {
            PLOG_DEBUG << "Joy UP" << std::endl;
            val1 |= 1 << 8;
        }
        if (Down)
        {
            PLOG_DEBUG << "Joy DOWN" << std::endl;
            val2 |= 1 << 9;
        }
        if (Left)
        {
            PLOG_DEBUG << "Joy LEFT" << std::endl;
            val1 |= 1 << 10;
        }
        if (Right)
        {
            PLOG_DEBUG << "Joy RIGHT" << std::endl;
            val2 |= 1 << 11;
        }
        if (joy.dwButtons & settings_.UpButtonCode)
        {
            PLOG_DEBUG << "Joy BUTTON UP" << std::endl;
            val1 |= 1 << 12;
        }
        if (joy.dwButtons & settings_.DownButtonCode)
        {
            PLOG_DEBUG << "Joy BUTTON DOWN" << std::endl;
            val2 |= 1 << 13;
        }
        if (joy.dwButtons & settings_.LeftButtonCode)
        {
            PLOG_DEBUG << "Joy BUTTON LEFT" << std::endl;
            val1 |= 1 << 14;
        }
        if (joy.dwButtons & settings_.RightButtonCode)
        {
            PLOG_DEBUG << "Joy BUTTON RIGHT" << std::endl;
            val2 |= 1 << 15;
        }
        if (joy.dwButtons & settings_.Button1Code)
        {
            PLOG_DEBUG << "Joy BUTTON 1" << std::endl;
            val1 |= 1 << 16;
        }
        if (joy.dwButtons & settings_.Button2Code)
        {
            PLOG_DEBUG << "Joy BUTTON 2" << std::endl;
            val2 |= 1 << 17;
        }
    }
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_I) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 1;
    }
    if (GetAsyncKeyState(VK_KEY_P) & 0x8000)
    {
        PLOG_DEBUG << "P1 SERVICE" << std::endl;
        val1 |= 1 << 3;
    }

    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        PLOG_DEBUG << "P2 SERVICE" << std::endl;
        val2 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_1) & 0x8000)
    {
        PLOG_DEBUG << "P1 START" << std::endl;
        val1 |= 1 << 4;
    }

    if (GetAsyncKeyState(VK_KEY_2) & 0x8000)
    {
        PLOG_DEBUG << "P2 START" << std::endl;
        val2 |= 1 << 5;
    }

    if (GetAsyncKeyState(settings_.testModeKeycode) & 0x8000)
    {
        PLOG_DEBUG << "TEST Node 1" << std::endl;
        val1 |= 1 << 6;
    }
    return val1 | val2;
}
