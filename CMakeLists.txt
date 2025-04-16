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
    src/main.cpp
    src/Model/Ant.cpp
    src/Model/Roles/Caretaker.cpp
    src/Model/Roles/Soldier.cpp
    src/Model/Roles/Forager.cpp
    src/Model/Roles/Builder.cpp
    src/Model/Roles/Cleaner.cpp
    src/Model/Roles/NoRole.cpp
    src/Model/Anthill.cpp
    src/Utils/TextureManager.cpp
    src/Utils/Random.cpp
    src/View/AntDrawable.cpp
    src/View/AnthillDrawable.cpp
    src/View/UI/AnthillInfoText.cpp
    src/Core/Simulation.cpp
    src/View/UI/HUD.cpp
    src/View/UI/FPSText.cpp
    src/View/Points/FoodPoint.cpp
    src/Model/Maps/FoodMap.cpp
    src/View/Background.cpp
    src/View/UI/AntInfoText.cpp
    src/View/UI/Logger.cpp
    src/Core/EventManager.cpp
    src/Model/Roles/Role.cpp
    src/Model/HiveMind.cpp
    src/Model/Store.cpp
    src/View/Points/WoodPoint.cpp
    src/Model/Maps/WoodMap.cpp
    src/View/Points/Point.cpp
    src/Model/Maps/Map.cpp
    src/Model/Enemy.cpp
    src/Model/EnemyController.cpp
    src/Model/Game.cpp
    src/Utils/Color.h
        src/View/Render/GlowedSprite.cpp
        src/View/Render/GlowedSprite.h
        src/View/Render/RoundedRect.cpp
        src/View/Render/RoundedRect.h
)
target_compile_features(anthill_simulation PRIVATE cxx_std_17)
target_link_libraries(anthill_simulation PRIVATE SFML::Graphics)
