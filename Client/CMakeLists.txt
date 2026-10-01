find_package(SDL3 REQUIRED CONFIG)
find_package(OpenGL REQUIRED)

add_executable(NetheriteClient
    src/main.cpp
    src/gl.c
)

target_include_directories(NetheriteClient
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(NetheriteClient
    PRIVATE
        NetherServer
        Nether
        SDL3::SDL3
        OpenGL::GL
)
