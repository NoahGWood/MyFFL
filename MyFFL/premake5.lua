project "MyFFL"
location "MyFFL"
kind "ConsoleApp"
language "C++"
cppdialect "C++2a"
staticruntime "off"
systemversion "latest"

targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
objdir ("%{wks.location}/build/" .. outputdir .. "/%{prj.name}")


files
{
    "%{wks.location}/MyFFL/**.h",
    "%{wks.location}/MyFFL/**.cpp",
    "%{wks.location}/MyFFL/platforms/**.h",
    "%{wks.location}/MyFFL/platforms/**.cpp",
    "%{wks.location}/Vendor/stb_image/**.h",
    "%{wks.location}/Vendor/stb_image/**.cpp",
}

includedirs
{
    "%{wks.location}/MyFFL/include",
    "%{wks.location}/MyFFL/platforms",
    "%{wks.location}/Vendor",
    "%{wks.location}/Vendor/spdlog/include",
    "%{IncludeDir.Glad}",
    "%{IncludeDir.ImGui}",
    "%{IncludeDir.stb_image}",
    "%{IncludeDir.tinyfiledialogs}",
    "%{IncludeDir.yaml}",
}
links 
{
    "glfw",
    "Glad",
    "ImGui",
    "yaml",
    "tinyfiledialogs",
}
defines
{
    "_CRT_SECURE_NO_WARNINGS",
    "GLFW_INCLUDE_NONE"
}
filter "system:windows"
    defines
    {
        "VM_PLATFORM_WINDOWS",
        "VM_BUILD_DLL"
    }
    links
    {
        "OpenGL32"
    }

filter "system:linux"
    pic "On"

    defines
    {
        "VM_PLATFORM_LINUX",
        "VM_BUILD_SHARED",
    }
    links
    {
        "dl",
        "GL",
        "imgui"
    }


filter "configurations:Debug"
    defines {
        "VM_DEBUG"
    }
    symbols "On"


filter "configurations:Release"
    defines "VM_RELEASE"
    optimize "On"

filter "configurations:Dist"
    defines "VM_DIST"
    optimize "On"
