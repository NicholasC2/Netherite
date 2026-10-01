cmake_minimum_required(VERSION 3.25)

project(Netherite
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libNether)
add_subdirectory(Server)
add_subdirectory(Client)
