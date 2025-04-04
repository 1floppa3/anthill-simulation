cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(anthill_simulation)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(
  anthill_simulation
  "src/main.cpp"
        src/Ant.h
        src/Ant.cpp
        src/Roles/Role.h
        src/Roles/NoRole.h
        src/Roles/Caretaker.cpp
        src/Roles/Caretaker.h
        src/Roles/Soldier.h
        src/Roles/Soldier.cpp
        src/Roles/Forager.h
        src/Roles/Forager.cpp
        src/Roles/Builder.h
        src/Roles/Builder.cpp
        src/Roles/Cleaner.h
        src/Roles/Cleaner.cpp
        src/Roles/NoRole.cpp
        src/Anthill.h
        src/Anthill.cpp
)
target_compile_features(anthill_simulation PRIVATE cxx_std_17)
target_link_libraries(anthill_simulation PRIVATE SFML::Graphics)
