add_library(NetherServer STATIC
    src/server.cpp
)

target_link_libraries(NetherServer
    PUBLIC Nether
)

target_include_directories(NetherServer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(NetheriteServer
    src/standalone/main.cpp
)

target_link_libraries(NetheriteServer
    PRIVATE NetherServer
)
