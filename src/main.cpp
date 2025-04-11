#include "Core/Simulation.h"

int main() {
    Core::Simulation simulation(sf::VideoMode::getDesktopMode().size);
    simulation.start_simulation();
}
