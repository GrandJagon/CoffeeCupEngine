project "CoffeeCupEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../obj/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",

        "vendors/glm/**.hpp",
        "vendors/glm/**.inl",
        "vendors/imgui/**.h",
        "vendors/imgui/**.cpp",
        "vendors/stb_image/**.h",
        "vendors/stb_image/**.cpp"
    }

    filter {"system:windows"}
        defines 
        {
            "WINDOWS"
        }
    
    filter {"system:linux"}
        defines
        {
            "LINUX"
        }

    filter {"configurations:Debug"}
        runtime "Debug"
        symbols "On"
        defines
        {
            "DEBUG"
        }

    filter {"configurations:Release"}
        runtime "Release"
        optimize "On"
        defines
        {
            "RELEASE"
        }
    