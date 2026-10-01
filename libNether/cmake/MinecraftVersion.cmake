set(MC_VERSION "26.3" CACHE STRING "Minecraft version")

if(MC_VERSION STREQUAL "26.3")
    set(MC_VERSION_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft/26.3/Blocks.cpp
    )
elseif(MC_VERSION STREQUAL "26.2")
    set(MC_VERSION_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft/26.2/Blocks.cpp
    )
else()
    message(FATAL_ERROR "Unsupported Minecraft version: ${MC_VERSION}")
endif()
