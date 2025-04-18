# Anthill Simulation

**Anthill Simulation** is a collaborative project developed as part of the C++ Programming  course at HSE. It is a simple 2D ant colony game built with SFML in C++, showcasing ant behaviors, resource management, and dynamic rendering with particle effects.

| Screenshot 1 | Screenshot 2 |
|:------------:|:------------:|
| ![image](https://github.com/user-attachments/assets/205c9b71-7dea-48cd-b487-19e893276886) | ![image](https://github.com/user-attachments/assets/69c55359-1d29-4770-a9ac-4905eef60cd6) |

## Features

- **Ant colony management**: Foragers, Builders, and potential Cleaners collect resources, build, and maintain the anthill.
- **Resource system**: Food and wood stores with capacities that evolve as the anthill upgrades.
- **Rank progression**: The anthill expands and gains new capabilities when enough wood is gathered.
- **Ant behaviors**: Aging, role assignment, health, and death handling with particle effects.
- **Particle effects**: Dust or death particles spawn upon events (e.g., ant removal).
- **MVC structure**: Clear separation of Model (logic), View (rendering), and Controller (input & simulation loop).

## Dependencies

- **C++20** or later
- **SFML 3.0.0** (Graphics, Window, System)
- **CMake** (build system)

## Controls

- **ESC**: Exit game
- **Mouse Left‑Click**: Remove ant at cursor
- **Key 1 / Up Arrow**: Spawn food resource
- **Key 2 / Down Arrow**: Spawn wood resource

