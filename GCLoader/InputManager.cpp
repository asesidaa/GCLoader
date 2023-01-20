#include "InputManager.h"
#include "keycodes.h"
#include "plog/Log.h"

DWORD InputManager::GetInput() const
{
    DWORD val1 = 0;
    DWORD val2 = 0;
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        PLOG_DEBUG <<"P1 SERVICE" << std::endl;
        val1 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_I) & 0x8000)
    {
        PLOG_DEBUG <<"P1 SERVICE"<< std::endl;
        val1 |= 1 << 1;
    }
    if (GetAsyncKeyState(VK_KEY_P) & 0x8000)
    {
        PLOG_DEBUG <<"P1 SERVICE"<< std::endl;
        val1 |= 1 << 3;
    }

    if (GetAsyncKeyState(VK_F2) & 0x8000)
    {
        PLOG_DEBUG <<"P2 SERVICE"<< std::endl;
        val2 |= 1 << 2;
    }

    if (GetAsyncKeyState(VK_KEY_1) & 0x8000)
    {
        PLOG_DEBUG <<"P1 START"<< std::endl;
        val1 |= 1 << 4;
    }

    if (GetAsyncKeyState(VK_KEY_2) & 0x8000)
    {
        PLOG_DEBUG <<"P2 START"<< std::endl;
        val2 |= 1 << 5;
    }

    if (GetAsyncKeyState(settings_.testModeKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"TEST Node 1"<< std::endl;
        val1 |= 1 << 6;
    }

    if (GetAsyncKeyState(settings_.p1UpKeycode) & 0x8000)

    {
        PLOG_DEBUG <<"P1 UP"<< std::endl;
        val1 |= 1 << 8;
    }
    if (GetAsyncKeyState(settings_.p2UpKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P2 UP"<< std::endl;
        val2 |= 1 << 9;
    }

    if (GetAsyncKeyState(settings_.p1DownKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P1 DOWN"<< std::endl;
        val1 |= 1 << 10;
    }

    if (GetAsyncKeyState(settings_.p2DownKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P2 DOWN"<< std::endl;
        val2 |= 1 << 11;
    }

    if (GetAsyncKeyState(settings_.p1LeftKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P1 LEFT"<< std::endl;
        val1 |= 1 << 12;
    }

    if (GetAsyncKeyState(settings_.p2LeftKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P2 LEFT"<< std::endl;
        val2 |= 1 << 13;
    }

    if (GetAsyncKeyState(settings_.p1RightKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P1 RIGHT"<< std::endl;
        val1 |= 1 << 14;
    }

    if (GetAsyncKeyState(settings_.p2RightKeycode) & 0x8000)
    {
        PLOG_DEBUG <<"P2 RIGHT"<< std::endl;
        val2 |= 1 << 15;
    }

    if (GetAsyncKeyState(settings_.p1Button1Keycode) & 0x8000)
    {
        PLOG_DEBUG <<"P1 BUTTON 1"<< std::endl;
        val1 |= 1 << 16;
    }

    if (GetAsyncKeyState(settings_.p2Button1Keycode) & 0x8000)
    {
        PLOG_DEBUG <<"P2 BUTTON 1"<< std::endl;
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
