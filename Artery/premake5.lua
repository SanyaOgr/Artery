
project "Artery"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    --staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cpp",
        "src/**.h"
    }
    -- SOME MAGIC
    excludes "src/last implementation/**.cpp"
    excludes "src/last implementation/**.h"
    -- END)

    includedirs { 
        "src", 
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.GLFW}" 
    }

    links { 
        "GLAD",
        "GLFW"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
        }

    filter "configurations:Debug"
        defines "ARTERY_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ARTERY_RELEASE"
        runtime "Release"
        optimize "on"	