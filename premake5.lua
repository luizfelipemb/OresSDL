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

        includedirs 
		{ 
		"vendor/SDL2-2.30.3/include",
		"vendor/SDL2_image-2.8.2/include"
		}
        libdirs 
		{ 
		"vendor/SDL2-2.30.3/lib/x64",
		"vendor/SDL2_image-2.8.2/lib/x64"
		}

        links { "SDL2main", "SDL2","SDL2_image" }
		
 -- Post-build action to copy SDL2.dll
        postbuildcommands {
            "{COPY} %{path.getabsolute('vendor/SDL2-2.30.3/lib/x64/SDL2.dll')} %{cfg.targetdir}",
			"{COPY} %{path.getabsolute('vendor/SDL2_image-2.8.2/lib/x64/SDL2_image.dll')} %{cfg.targetdir}"
        }