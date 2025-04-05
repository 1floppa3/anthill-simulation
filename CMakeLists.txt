cmake_minimum_required(VERSION 3.29)
project(anthill-simulation)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

add_executable(simulation main.cpp TextureManager.cpp Anthill.cpp ant.cpp)

target_link_libraries(simulation sfml-graphics sfml-window sfml-system)