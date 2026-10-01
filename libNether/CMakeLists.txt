include(cmake/MinecraftVersion.cmake)

add_library(Nether STATIC
    src/blocks/Block.cpp
    src/blocks/BlockRegistry.cpp
    
    src/Nether.cpp

    ${MC_VERSION_SOURCES}
)

target_include_directories(Nether
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
