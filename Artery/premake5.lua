
project "Artery"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    --staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "artpch.h"
	pchsource "src/artpch.cpp"

    files {
        "src/**.cpp",
        "src/**.h"
    }
    
    -- SOME MAGIC
    excludes "src/non-working/**.cpp"
    excludes "src/non-working/**.h"
    -- END

    includedirs { 
        "src", 
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.spdlog}"
    }

    links { 
        "GLAD",
        "opengl32.lib"
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