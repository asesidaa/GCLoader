#include "Settings.h"
#include <fstream>
#include <filesystem>
#include <plog/Log.h>

Settings GetFromInput(const std::string& filename) {
    HMODULE module = GetModuleHandleW(nullptr);
    WCHAR modulePath[MAX_PATH];
    GetModuleFileNameW(module, modulePath, MAX_PATH);
    std::filesystem::path path(modulePath);
    path = path.parent_path() / filename;
    PLOG_DEBUG << "Config file path: " << path << std::endl;
    std::ifstream input;
    Settings settings {};
    input.exceptions( std::ifstream::failbit | std::ifstream::badbit );
    try
    {
        input.open(path);
        input >> configor::json::wrap(settings);
    }
    catch (std::ifstream::failure&)
    {
        wchar_t buf[1024];
        FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                       nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
                       buf, (sizeof(buf) / sizeof(wchar_t)), nullptr);
        PLOG_ERROR << "Failed to open config file! Error is: " << buf << std::endl; 
    }
    catch (configor::configor_deserialization_error& e)
    {
        PLOG_ERROR << "Failed to parse config json file! Error is " << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        PLOG_ERROR << "Unknown exception! Error is " << e.what() << std::endl;
    }

    return settings;
}