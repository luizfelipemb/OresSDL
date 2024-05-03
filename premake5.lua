workspace "OresSDL"
    platforms { "Windows" }
    configurations { "Debug", "Release" }
    flags "MultiProcessorCompile"

project "OresSDL"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    targetdir "bin/%{cfg.system}-%{cfg.buildcfg}/%{cfg.architecture}"
    objdir "bin-int/%{cfg.system}-%{cfg.buildcfg}/%{cfg.architecture}"

    files { "src/**.cpp", "src/**.h", }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
    

    filter "platforms:Windows"
        system "Windows"
        architecture "x86_64"


    filter "system:windows"
        system "Windows"

        includedirs { "SDL2-2.30.3/include" }
        libdirs { "SDL2-2.30.3/lib/x64" }

        links { "SDL2main", "SDL2" }
		
 -- Post-build action to copy SDL2.dll
        postbuildcommands {
            "{COPY} %{path.getabsolute('SDL2-2.30.3/lib/x64/SDL2.dll')} %{cfg.targetdir}"
        }