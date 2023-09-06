#pragma once

namespace MyFFL
{
    class Settings
    {
        Settings() = default;
        ~Settings() = default;
        
        void SaveSettings(std::string& fname);
        void LoadSettings(std::string& fname);
    };
} // namespace MyFFL