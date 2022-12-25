project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	--staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Artery/vendor/spdlog/include",
		"%{wks.location}/Artery/src",
		"%{wks.location}/Artery/vendor",
		"%{IncludeDir.GLAD}"
	}

	links
	{
		"Artery"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ARTERY_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ARTERY_RELEASE"
		runtime "Release"
		optimize "on"