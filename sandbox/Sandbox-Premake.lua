na2 = "%{wks.location}/natrium2/"

project "Sandbox"
    location "./"
    targetname "%{prj.name}-bin"
    kind "ConsoleApp"
    staticruntime "off"

    language "C++"
    cppdialect "C++20"
    systemversion "latest"

    pchheader "Pch.hpp"
    pchsource "src/Pch.cpp"

    files {
        "**.hpp",
        "**.cpp"
    }

    includedirs {
        "./",
        "src/",
        "%{na2}include/",
        "%{na2}%{IncludeDirectories.fmt}",
        "%{na2}dependencies/"
    }

    links {
        "Natrium2",
        "fmt"
    }

    filter "system:linux"
        links {

        }

        defines { "NA2_PLATFORM_LINUX" }

    filter "system:windows"
        includedirs {

        }

        libdirs {

        }

        links {
            
        }

        defines { "NA2_PLATFORM_WINDOWS" }

        buildoptions { "/utf-8" }

    filter "toolset:msc"
        defines { "_CRT_SECURE_NO_WARNINGS" }

    filter "configurations:dbg"
        symbols "On"
        defines { "NA2_CONFIG_DEBUG" }

    filter "configurations:rel"
        optimize "speed"
        symbols "off"
        defines { "NA2_CONFIG_RELEASE" }

    filter "configurations:dist"
        kind "WindowedApp"
        optimize "speed"
        symbols "off"
        defines { "NA2_CONFIG_DIST" }