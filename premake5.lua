workspace "MyFFL"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    group "Dependencies"
        include "depends"
        include "Vendor/glad"
        include "Vendor/imgui"
        include "Vendor/yaml"
        include "Vendor/tinyfiledialogs"
    --    include "Vendor/nbis"
    
    group ""
    
    include "MyFFL"