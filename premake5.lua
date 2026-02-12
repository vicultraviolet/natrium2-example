OutputDirectory = "%{cfg.buildcfg}-%{cfg.system}"

workspace "Natrium2Example"
    architecture "x64"
    configurations { "dbg", "rel", "dist" }
    startproject "Sandbox"

    targetdir "bin/%{OutputDirectory}/%{prj.name}/"
    objdir "bin-int/%{OutputDirectory}/%{prj.name}/"

    debugdir "%{wks.location}"

include "natrium2/Natrium2-Premake.lua"
include "sandbox/Sandbox-Premake.lua"
