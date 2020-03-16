workspace "antech-engine"
 architecture "x64"

 configurations
 {
  "Debug",
  "Release",
  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 IncludeDir = {}
 IncludeDir["GLFW"] = "antech-engine/vendor/GLFW/include"

 include "antech-engine/vendor/GLFW"

 project "antech-engine"
 location "antech-engine"
 kind "SharedLib"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 pchheader "hzpch.h"
 pchsource "antech-engine/src/hzpch.cpp"

 files
 {
  "%{prj.name}/src/**.h",
  "%{prj.name}/src/**.cpp"
 }

 includedirs
 {
  "%{prj.name}/src",
  "%{prj.name}/vendor/spdlog/include",
  "%{IncludeDir.GLFW}"
 }

 links
 {
   "GLFW",
   "opengl32.lib"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "AT_PLATFORM_WINDOWS",
   "AT_BUILD_DLL"
  }

  postbuildcommands
  {
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
  }

 filter "configurations:Debug"
  defines "AT_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "AT_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "AT_DIST"
  optimize "On"

project "Sandbox"
 location "Sandbox"
 kind "ConsoleApp"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/src/**.h",
  "%{prj.name}/src/**.cpp"
 }

 includedirs
 {
  "antech-engine/vendor/spdlog/include",
  "antech-engine/src"
 }

 links
 {
  "antech-engine"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "AT_PLATFORM_WINDOWS"
  }

 filter "configurations:Debug"
  defines "AT_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "AT_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "AT_DIST"
  optimize "On"